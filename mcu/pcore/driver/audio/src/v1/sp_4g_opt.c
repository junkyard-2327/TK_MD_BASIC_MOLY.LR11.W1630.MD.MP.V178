#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "sync_data.h"

#include "l1aud_common_def.h"
#include "l1audio.h"
#include "am.h"
#include "l1audio_trace.h"
#include "media.h" 
#include "l1sp_trc.h"

#include "sal_exp.h"
#include "sal_def.h"

#include "sp_4g_opt.h"
//#include "pcmrb.h"

uint16 aud_id_sp4gToneDete;

#define FRAME_SIZE    (320)
#define PATTERN_SIZE    (FRAME_SIZE*3)
#define BUFFER_SIZE    (FRAME_SIZE*4)
#define PATTERN_COR_THRD    (160799699177 * 0.75)
#define PATTERN_SEARCH_STEP    (10)
#define PATTERN_SEARCH_COUNT    (32)
#define PATTERN_ENG_THRD    (100000000)
#define FRAME_COUNT_MAX    (50*60*60*10)

int16 sp4g_frame_count;
int16 sp4g_last_tone_frame;
int16 sp4g_tone_frame_dur[2];
int16 sp4g_tone_frame_dur_index;
int16 sp4g_tone_frame_count;
int16 sp4g_tone_frame_dur_hit_count;
uint16 sp4g_pattern_flag;
int16 sp4g_detect_buffer[BUFFER_SIZE];
int16 sp4g_detect_buffer_index;
extern int16 sp4g_tone_pattern[PATTERN_SIZE];

uint16 sp4gPatternDetecion(int16* input, int16 input_index, int16 input_size, int16 frame);
uint16 sp4gToneSearch(int16 *input, int16 input_index, uint16 input_size, int16 *pattern, uint16 length, uint16 correlation_count, uint16 step);
uint16 sp4gToneDetection(int16 *x, int16 index_x, uint16 size_x, int16 *pattern, uint16 length);


uint16 sp4gToneDeteGetAudID(void)
{
   return( aud_id_sp4gToneDete );
}


void sp4gToneDeteSetAudID(uint16 u16AudID)
{
   aud_id_sp4gToneDete = u16AudID;
}


void sp4gToneDeteInit(void)
{
   aud_id_sp4gToneDete = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id_sp4gToneDete );
   L1Audio_SetEventHandler( aud_id_sp4gToneDete, sp4gToneDeteExec );
}


void sp4gToneDeteClose(void)
{
   L1Audio_ClearFlag( aud_id_sp4gToneDete );
   L1Audio_FreeAudioID( aud_id_sp4gToneDete );
}


void sp4gToneDeteTaskInit(void)
{
    kal_prompt_trace(MOD_L1SP, "SP4G sp4gToneDeteTaskInit\n");

    uint16 i =0;
    sp4g_frame_count = 0;
    sp4g_last_tone_frame = -1;
    sp4g_tone_frame_dur[0] = 0;
    sp4g_tone_frame_dur[1] = 0;
    sp4g_tone_frame_dur_index = 0;
    sp4g_tone_frame_count = 0;
    sp4g_pattern_flag = 0;
    sp4g_tone_frame_dur_hit_count = 0;
    sp4g_detect_buffer_index = 0;

    for (i=0; i<BUFFER_SIZE; i++)
    {
        sp4g_detect_buffer[i] = 0;
    }

}


void sp4gToneDeteExec()
{
    int16   fsize, i;
    volatile uint16* ptr;

    kal_prompt_trace(MOD_L1SP, "SP4G sp4gToneDeteExec frame %d\n", sp4g_frame_count);

    fsize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SD);
    ptr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SD);

    if(fsize != 320)
    {
//        kal_prompt_trace(MOD_L1SP, "SP4G sp4gToneDeteExec not WB, frame size = %d\n", fsize);
        sp4g_pattern_flag = 0;
        return;
    }

    for(i=0;i<fsize;i++)
    {
        sp4g_detect_buffer[sp4g_detect_buffer_index + i] = ptr[i];
    }
//    PCMRB_Write_from_DSP(&sp4g_detect_buffer[sp4g_detect_buffer_index], ptr, fsize);     

//    kal_prompt_trace(MOD_L1SP, "SP4G sp4gToneDeteExec data %d, %d\n", sp4g_detect_buffer[sp4g_detect_buffer_index], sp4g_detect_buffer[sp4g_detect_buffer_index+1]);

    sp4g_detect_buffer_index += FRAME_SIZE;
    sp4g_detect_buffer_index %= BUFFER_SIZE;
    
    sp4gPatternDetecion(sp4g_detect_buffer, sp4g_detect_buffer_index, BUFFER_SIZE, sp4g_frame_count);
    sp4g_frame_count ++;
    if (sp4g_frame_count > FRAME_COUNT_MAX)
        sp4g_frame_count = 0;
}


int32 sp4gToneDeteGetResult(void)
{
   return(sp4g_pattern_flag);
}


uint16 sp4gPatternDetecion(int16* input, int16 input_index, int16 input_size, int16 frame)
{
    int dur;
    if (sp4g_last_tone_frame > 0)
    {
        if (frame - sp4g_last_tone_frame < 15)
        {
            return sp4g_pattern_flag;
        }
    }

    if (sp4gToneSearch(input, input_index, input_size, sp4g_tone_pattern, PATTERN_SIZE, PATTERN_SEARCH_COUNT, PATTERN_SEARCH_STEP) == 1)
    {
//        printf("tone frame: %d\n", frame);
        kal_prompt_trace(MOD_L1SP, "SP4G tone frame: %d\n", frame);
        sp4g_tone_frame_count ++;
        if(sp4g_tone_frame_count == 1 || (frame < sp4g_last_tone_frame))
        {
            sp4g_last_tone_frame = frame;
            return sp4g_pattern_flag;
        }        

        dur = frame - sp4g_last_tone_frame;
        sp4g_last_tone_frame = frame;
        if ((dur > sp4g_tone_frame_dur[0] - 10) && (dur < sp4g_tone_frame_dur[0] + 10))
        {
            sp4g_tone_frame_dur[0] = dur;
            sp4g_tone_frame_dur_index = 1;
            sp4g_tone_frame_dur_hit_count ++;
        }
       else if ((dur > sp4g_tone_frame_dur[1] - 10) && (dur < sp4g_tone_frame_dur[1] + 10))
        {
            sp4g_tone_frame_dur[1] = dur;
            sp4g_tone_frame_dur_index = 0;
            sp4g_tone_frame_dur_hit_count ++;
        }
        else
        {
            sp4g_tone_frame_dur[sp4g_tone_frame_dur_index++] = dur;
            sp4g_tone_frame_dur_hit_count --;
            sp4g_tone_frame_dur_index %= 2;
        }
        if(sp4g_tone_frame_dur_hit_count > 8)
        {
            sp4g_tone_frame_dur_hit_count = 8;
        }            
        else if(sp4g_tone_frame_dur_hit_count < 0)
        {
            sp4g_tone_frame_dur_hit_count = 0;
        }
        
        if(sp4g_tone_frame_dur_hit_count >= 4)
        {
            sp4g_pattern_flag = 1;
        }
        else
        {
            sp4g_pattern_flag = 0;
        }
    }
    else if (sp4g_pattern_flag == 1)
    {
        if (frame < sp4g_last_tone_frame  && frame > 3000)
        {
            sp4g_pattern_flag = 0;
        }
        else if (frame - sp4g_last_tone_frame > 3000)
        {
            sp4g_pattern_flag = 0;
        }
    }

    return sp4g_pattern_flag;
}

uint16 sp4gToneSearch(int16 *input, int16 input_index, uint16 input_size, int16 *pattern, uint16 length, uint16 correlation_count, uint16 step)
{
	int i=0;
    uint16 r;

    for (i=0; i < correlation_count; i ++)
    {
        r = sp4gToneDetection( input, input_index, input_size, pattern, length);
        if(r == 1)
        {
            return 1;
        }
        input_index += step;
        input_index %= input_size;
	}
    return 0;
}

uint16 sp4gToneDetection(int16 *x, int16 index_x, uint16 size_x, int16 *pattern, uint16 length)
{
    int i,n = length;
    long long sum_xy=0, sum_x2=0, cor;
    int16* y = pattern;
    
    index_x %= size_x;  
    for (i=0; i<n; i++) 
    {
        sum_x2 += x[index_x] * x[index_x];
        sum_xy += x[index_x] * y[i];
        index_x ++;
        index_x %= size_x;
    }

    if (sum_x2==0)
    {
        cor = 0;
    }
    else
    {
        cor =  (sum_xy<<10) / sum_x2 * (sum_xy>>10) ;
    }    
    if (cor >= PATTERN_COR_THRD && sum_x2 > PATTERN_ENG_THRD)   
    {
        return 1;
    }
    return 0;
}

int16 sp4g_tone_pattern[] = {
    -17, -15, -6, 0, 0, 4, 19, 18, 3, 6, 
    0, 3, 3, 6, 6, 3, 6, -10, 0, 9, 
    -4, 9, 0, -4, -4, 0, 9, 12, 9, 12, 
    12, 11, 8, 17, 17, 11, 23, 20, 23, 23, 
    17, 17, 8, 5, 0, 5, 11, 20, 26, 20, 
    17, 17, 11, 17, 17, 17, 17, 14, 20, 29, 
    29, 32, 29, 14, -9, -21, -18, -3, 14, 37, 
    69, 86, 103, 103, 97, 88, 77, 63, 48, 31, 
    17, 11, 17, 28, 42, 51, 48, 25, 8, -9, 
    -3, 22, 64, 104, 140, 181, 190, 167, 139, 86, 
    27, -59, -137, -189, -228, -214, -178, -142, -109, -75, 
    -39, -50, -28, -20, 0, 32, 90, 164, 233, 318, 
    351, 348, 269, 163, 43, -82, -197, -279, -314, -303, 
    -273, -184, -90, 24, 129, 197, 280, 307, 334, 345, 
    353, 361, 361, 355, 360, 315, 251, 167, 66, -67, 
    -194, -321, -421, -466, -432, -337, -190, -48, 78, 166, 
    205, 192, 166, 158, 117, 106, 72, 43, 18, -39, 
    -73, -65, -119, -174, -254, -318, -369, -354, -305, -267, 
    -195, -126, -29, 114, 236, 299, 205, -3, -165, -297, 
    -325, -270, -184, -104, 7, 90, 243, 415, 495, 578, 
    659, 624, 649, 639, 538, 565, 580, 553, 494, 358, 
    212, -35, -250, -482, -608, -842, -781, -1082, -5063, -10608, 
    -14287, -16473, -17101, -15973, -13490, -9797, -5053, 429, 6234, 12133, 
    17626, 22382, 26367, 28962, 30223, 29931, 28025, 24744, 20133, 14292, 
    7934, 1175, -5688, -12229, -18062, -22994, -26679, -28704, -29474, -28716, 
    -26330, -22555, -17726, -11994, -5667, 833, 7128, 12935, 17787, 21632, 
    24101, 25152, 24644, 22450, 19064, 14579, 9205, 3182, -3083, -9246, 
    -15068, -19889, -23866, -26584, -27980, -27844, -26238, -23333, -19133, -13726, 
    -7894, -1606, 4697, 10719, 16128, 20657, 23896, 25689, 26154, 25219, 
    22902, 19327, 14697, 9228, 3308, -2747, -8547, -13952, -18499, -22025, 
    -24323, -25273, -24783, -22719, -19588, -15272, -10116, -4268, 1864, 7850, 
    13446, 18382, 22221, 24955, 26367, 26285, 24804, 22021, 18102, 13190, 
    7616, 1654, -4279, -10018, -15143, -19380, -22533, -24485, -25069, -24217, 
    -21921, -18348, -13775, -8397, -2477, 3588, 9424, 14753, 19310, 22783, 
    24957, 25790, 25266, 23367, 20167, 15913, 10791, 5111, -851, -6820, 
    -12407, -17368, -21385, -24199, -25680, -25688, -24325, -21567, -17554, -12585, 
    -7040, -1093, 4845, 10537, 15621, 19798, 22930, 24744, 25231, 24279, 
    22014, 18504, 13983, 8655, 2816, -3247, -9114, -14563, -19204, -22802, 
    -25136, -26057, -25551, -23563, -20361, -16036, -10879, -5201, 801, 6710, 
    12208, 17063, 20935, 23682, 25110, 25162, 23805, 21126, 17278, 12453, 
    6923, 939, -5112, -10888, -16062, -20341, -23497, -25278, -25662, -24609, 
    -22231, -18678, -14112, -8754, -2938, 3021, 8833, 14142, 18710, 22265, 
    24606, 25590, 25224, 23409, 20354, 16133, 10962, 5180, -917, -6918, 
    -12529, -17406, -21229, -23915, -25245, -25192, -23777, -21054, -17171, -12332, 
    -6836, -951, 5041, 10723, 15848, 20134, 23353, 25275, 25870, 24993, 
    22719, 19155, 14518, 9057, 3097, -3011, -8863, -14188, -18709, -22186, 
    -24476, -25363, -24880, -23071, -19964, -15774, -10716, -5024, 905, 6852, 
    12419, 17381, 21391, 24225, 25707, 25730, 24293, 21466, 17470, 12462, 
    6832, 883, -5114, -10766, -15851, -20039, -23143, -24994, -25482, -24587, 
    -22346, -18860, -14314, -9007, -3182, 2875, 8775, 14220, 18872, 22468, 
    24779, 25705, 25206, 23209, 19985, 15717, 10570, 4852, -1091, -6989, 
    -12516, -17348, -21198, -23966, -25404, -25435, -24101, -21376, -17532, -12634, 
    -7102, -1142, 4894, 10727, 15913, 20203, 23360, 25168, 25550, 24528, 
    22212, 18630, 14113, 8755, 2970, -2989, -8774, -14125, -18684, -22255, 
    -24591, -25564, -25134, -23314, -20241, -16005, -10859, -5081, 994, 7017, 
    12639, 17476, 21297, 23965, 25344, 25286, 23909, 21173, 17301, 12484, 
    7028, 1103, -4842, -10522, -15667, -19937, -23159, -25072, -25657, -24792, 
    -22538, -18996, -14392, -8961, -3022, 3064, 8871, 14189, 18723, 22265, 
    24593, 25592, 25148, 23376, 20274, 16079, 11016, 5315, -660, -6633, 
    -12296, -17248, -21261, -24119, -25608, -25677, -24303, -21516, -17565, -12614, 
    -7085, -1157, 4838, 10623, 15821, 20149, 23353, 25224, 25705, 24777, 
    22505, 18957, 14347, 8946, 2981, -3091, -9025, -14470, -19151, -22769, 
    -25134, -26046, -25537, -23572, -20328, -16027, -10832, -5033, 1008, 7021, 
    12655, 17584, 21519, 24284, 25653, 25645, 24193, 21396, 17429, 12464, 
    6892, 954, -5081, -10879, -16064, -20356, -23443, -25244, -25591, -24570, 
    -22209, -18620, -14005, -8609, -2747, 3230, 9009, 14342, 18888, 22418, 
    24707, 25612, 25096, 23165, 20029, 15779, 10707, 5093, -846, -6756, 
    -12325, -17263, -21107, -23916, -25382, -25455, -24145, -21515, -17750, -12962, 
    -7564, -1648, 4290, 9979, 15175, 19458, 22631, 24612, 25263, 24497, 
    22368, 18995, 14522, 9399, 3466, -2450, -8241, -13424, -14343, -12704, 
    -11669, -10526, -9502, -8596, -7673, -6873, -6153, -5468, -4840, -4311, 
    -3749, -3367, -3007, -2563, -2292, -1921, -1681, -1391, -1131, -975, 
    -564, -165, 204, 581, 939, 1352, 1678, 1969, 2207, 2371, 
    2429, 2351, 2318, 2211, 2158, 2133, 2027, 1987, 1987, 1931, 
    1920, 1942, 1862, 1744, 1744, 1776, 1787, 1809, 1847, 1896, 
    1882, 1829, 1780, 1738, 1632, 1463, 1281, 1123, 916, 761, 
    576, 428, 357, 280, 240, 182, 111, -18, -163, -236, 
    -283, -338, -318, -325, -258, -283, -307, -294, -314, -334, 
    -385, -447, -507, -591, -691, -733, -786, -800, -800, -789, 
    -764, -782, -902, -969, -977, -966, -924, -886, -766, -709, 
    -697, -611, -575, -560, -536, -577, -582, -586, -580, -586, 
    -617, -560, -487, -494, -438, -345, -389, -443, -409, -394, 
    -361, -314, -263, -174, -98, -16, 11, 48, 73, 75, 
    82, 71, 57, 59, 73, 104, 117, 133, 180, 204, 
    224, 237, 233, 237, 244, 233, 266, 282, 300, 326, 
    335, 344, 351, 322, 311, 311, 304, 306, 302, 300, 
    300, 295, 308, 322, 304, 295, 284, 280, 257, 253, 
    237, 226, 215, 208, 197, 195, 182, 175, 168, 151, 
    144, 133, 131, 117, 108, 86, 79, 66, 48, 44, 
    24, 19, 15, 0, 0, -18, -25, -41, -43, -58, 
    -67, -72, -83, -85, -78, -94, -105, -112, -118, -121, 
    -132, -143, -154, -156, -158, -149, -141, -149, -163, -181, 
    -178, -181, -185, -178, -183, -189, -185, -181, -189, -189, 
    -192, -183, -169, -169, -165, -152, -156, -143, -118, -114, 
    -125, -116, -114, -94, -85, -78, -83, -85, -74, -72, 
    -69, -62, -62, -60, -44, -48, -50, -48, -45, -25
};
