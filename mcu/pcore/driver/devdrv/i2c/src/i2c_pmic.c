
#if defined(MT6290)
#include "i2c_pmic.h"
#include "drvpdn.h"


I2C_CFG g_i2cCfg;

void i2c_set_transaction_speed(I2C_TRANSACTION_MODE mode , kal_uint16 speed)
{
	kal_uint32	step_cnt_div;
	kal_uint32	sample_cnt_div;
	kal_uint32	temp;

	//Fast Mode Speed
if (mode==I2C_TRANSACTION_FAST_MODE){
	for (sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
	{
		
		temp=((speed)*2*sample_cnt_div);	

		step_cnt_div=(I2C_CLOCK_RATE+temp-1)/temp;	//cast the <1 part
   
		if (step_cnt_div<=64) 
		{
			break;
		}
	}
	if (step_cnt_div>64 && sample_cnt_div>8)
	{
		step_cnt_div=64;
		sample_cnt_div=8;
	}
  
       g_i2cCfg.speed = I2C_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 
	g_i2cCfg.sample_cnt_div=sample_cnt_div-1;
	g_i2cCfg.step_cnt_div=step_cnt_div-1;
	g_i2cCfg.mode = I2C_TRANSACTION_FAST_MODE;
////MSG(MSG_ERR,"Fast_Mode_Speed = %d,sample_cnt_div = %d, step_cnt_div = %d\r\n",(*Fast_Mode_Speed),i2c_handle[owner].fs_sample_cnt_div,i2c_handle[owner].fs_step_cnt_div);
//	        i2c_handle[owner].i2c_config.transaction_mode=I2C_TRANSACTION_FAST_MODE;
	
}else  
	//HS Mode Speed
	if (mode==I2C_TRANSACTION_HIGH_SPEED_MODE) 
	{ 
		for (sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
		{
	
			temp=((speed)*2*sample_cnt_div);	
			step_cnt_div=(I2C_CLOCK_RATE+temp-1)/temp;
			if (step_cnt_div<=8) 
			{
				break;
			}
		}
	       g_i2cCfg.speed = I2C_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 
		g_i2cCfg.sample_cnt_div=sample_cnt_div-1;
		g_i2cCfg.step_cnt_div=step_cnt_div-1;
		g_i2cCfg.mode = I2C_TRANSACTION_HIGH_SPEED_MODE;
//MSG(MSG_ERR,"HS_Mode_Speed = %d,hs_sample_cnt_div = %d, hs_step_cnt_div = %d\r\n",(*HS_Mode_Speed),i2c_handle[owner].hs_sample_cnt_div,i2c_handle[owner].hs_step_cnt_div);
//			i2c_handle[owner].i2c_config.transaction_mode=I2C_TRANSACTION_HIGH_SPEED_MODE;
	}
}

kal_bool  i2c_set_speed(kal_uint16 speed_kb)
{
	DRV_WriteReg32(0xBF8A0188, 0xc00);
	if (speed_kb < 400)
	{
		i2c_set_transaction_speed(I2C_TRANSACTION_FAST_MODE,speed_kb);
	}
	else if (speed_kb < 2000)
	{
		i2c_set_transaction_speed(I2C_TRANSACTION_HIGH_SPEED_MODE,speed_kb);
	}
	else 
	{
		return KAL_FALSE;
	}
	return KAL_TRUE;	
}

#if I2C_PMIC_DRV_TEST
kal_uint32 i2c_wait_complete_max = 100000;
#endif
I2C_STATUS i2c_pmic_reg_read(kal_uint8 slave_addr , kal_uint8 reg , kal_uint8 * pval)
{
	kal_uint32 cnt = 100000;
	kal_uint32 int_sts =0;
	kal_uint32 fifo_sts = 0;
	I2C_STATUS ret_sts;
//	kal_uint32 speed;
 	// Power on I2C
 	PDN_CLR(PDN_I2C);
 	// reset I2C
 	DRV_WriteReg32(REG_I2C_SOFTRESET, 0x01);
 	// set to open-drain mode
 	DRV_WriteReg32(REG_I2C_IO_CONFIG, 0x03);
 	// always enable ack error detection
 	ENABLE_I2C_ACK_ERR_DET; //Always enable ack error detection
 	// always enable nack error detection
 	ENABLE_I2C_NAKERR_DET;  
	// clear FIFO
	CLEAR_I2C_FIFO;
	// clear STA
	CLEAR_I2C_STA;
 	// set slave address
 	 slave_addr  = (slave_addr << 1);
 	SET_I2C_SLAVE_ADDRESS(slave_addr , I2C_WRITE_BIT);


	i2c_set_speed(FS_300K);
	if (g_i2cCfg.mode == I2C_TRANSACTION_FAST_MODE)
	{// full speed
		SET_I2C_FAST_MODE;
		SET_I2C_STEP_CNT_DIV(g_i2cCfg.step_cnt_div);
		SET_I2C_SAMPLE_CNT_DIV(g_i2cCfg.sample_cnt_div);
		// turn off driving 1
		DRV_WriteReg(REG_I2C_IO_CONFIG,0x03);
	}
	else
	{// high speed
		// set transaction mode 
 		SET_I2C_HS_MODE;
 		// set speed 
 		SET_I2C_HS_STEP_CNT_DIV(g_i2cCfg.step_cnt_div);
		SET_I2C_HS_SAMPLE_CNT_DIV(g_i2cCfg.sample_cnt_div);
 		 // turn on driving 
 	 	DRV_WriteReg(REG_I2C_IO_CONFIG, 0x00);	//turn on driving 1
	}

	// set transfer num 
	SET_I2C_TRANSACTION_LENGTH(2)
 	// set transfer length 
 	SET_I2C_TRANSFER_LENGTH(1);
 	// set AUX transfer length 
 	SET_I2C_AUX_TRANSFER_LENGTH(1)
 	// set RS
 	SET_I2C_RS_BETWEEN_TRANSFER;
 	ENABLE_I2C_DIR_CHANGE;
	// write reg address 
	DRV_I2C_WriteReg16(REG_I2C_DATA_PORT,reg);
 	// start I2C
 	START_I2C_TRANSACTION;
	do {
			if(0 == (DRV_I2C_ReadReg16(REG_I2C_START)&0x01)) {//if(0 != DRV_I2C_ReadReg16(REG_I2C_INT_STA)) { //old
				break;
			}	
	} while((DRV_I2C_ReadReg16(REG_I2C_FIFO_STAT)>>4)&0x0f);
 	// read data
 	cnt = 100000;
 	do {
		fifo_sts = DRV_I2C_ReadReg16(REG_I2C_FIFO_STAT);
		cnt --;
	}while((fifo_sts & 0x01 ) && (0 != cnt));
	if (cnt != 0)
	{
	*pval = DRV_I2C_ReadReg16(REG_I2C_DATA_PORT) & 0xff;
	}
	
	// read Int status 
	#if I2C_PMIC_DRV_TEST
	cnt = i2c_wait_complete_max;//300000 ; 
	#else
	cnt = I2C_WAIT_TIMEOUT;
	#endif
	do
	{
		int_sts = DRV_I2C_ReadReg16(REG_I2C_INT_STA);
		cnt -- ;
	}while(((int_sts & I2C_TRANSAC_COMPLETE) ==0 ) && (0 != cnt));



	if (int_sts == I2C_TRANSAC_COMPLETE)
	{
		ret_sts =  I2C_PASS;
	}
	else
	{
		if (int_sts & I2C_TRANSAC_ACK_ERR)
		{
			ret_sts = I2C_ACKERR;
		}
		else if (int_sts & I2C_HS_NACK_ERR)
		{
			ret_sts = I2C_NACKERR;
		}
		else 
		{
			I2C_PRINT("[I2C_FAIL]READ REG INT STS :%x\r\n ",int_sts);
			ret_sts = I2C_FAIL;
		}
	}
	// power down 
	PDN_SET(PDN_I2C);
	return ret_sts; 
}

I2C_STATUS i2c_pmic_reg_read_more(kal_uint8 slave_addr , kal_uint8 reg , kal_uint8 * pval ,kal_uint8 num)
{
	kal_uint32 cnt = 100000;
	kal_uint32 int_sts =0 , i =0;
	kal_uint32 fifo_sts = 0;
	I2C_STATUS ret_sts;
//	kal_uint32 speed;
 	// Power on I2C
 	PDN_CLR(PDN_I2C);
 	// reset I2C
 	DRV_WriteReg32(REG_I2C_SOFTRESET, 0x01);
 	// set to open-drain mode
 	DRV_WriteReg32(REG_I2C_IO_CONFIG, 0x03);
 	// always enable ack error detection
 	ENABLE_I2C_ACK_ERR_DET; //Always enable ack error detection
 	// always enable nack error detection
 	ENABLE_I2C_NAKERR_DET;  
	// clear FIFO
	CLEAR_I2C_FIFO;
	// clear STA
	CLEAR_I2C_STA;
 	// set slave address
 	 slave_addr  = (slave_addr << 1);
 	SET_I2C_SLAVE_ADDRESS(slave_addr , I2C_WRITE_BIT);


	i2c_set_speed(FS_300K);
	if (g_i2cCfg.mode == I2C_TRANSACTION_FAST_MODE)
	{// full speed
		SET_I2C_FAST_MODE;
		SET_I2C_STEP_CNT_DIV(g_i2cCfg.step_cnt_div);
		SET_I2C_SAMPLE_CNT_DIV(g_i2cCfg.sample_cnt_div);
		// turn off driving 1
		DRV_WriteReg(REG_I2C_IO_CONFIG,0x03);
	}
	else
	{// high speed
		// set transaction mode 
 		SET_I2C_HS_MODE;
 		// set speed 
 		SET_I2C_HS_STEP_CNT_DIV(g_i2cCfg.step_cnt_div);
		SET_I2C_HS_SAMPLE_CNT_DIV(g_i2cCfg.sample_cnt_div);
 		 // turn on driving 
 	 	DRV_WriteReg(REG_I2C_IO_CONFIG, 0x00);	//turn on driving 1
	}

	// set transfer num 
	SET_I2C_TRANSACTION_LENGTH(2)
 	// set transfer length 
 	SET_I2C_TRANSFER_LENGTH(1);
 	// set AUX transfer length 
 	SET_I2C_AUX_TRANSFER_LENGTH(num)
 	// set RS
 	SET_I2C_RS_BETWEEN_TRANSFER;
 	ENABLE_I2C_DIR_CHANGE;
	// write reg address 
	DRV_I2C_WriteReg16(REG_I2C_DATA_PORT,reg);
 	// start I2C
 	START_I2C_TRANSACTION;
	do {
			if(0 == (DRV_I2C_ReadReg16(REG_I2C_START)&0x01)) {//if(0 != DRV_I2C_ReadReg16(REG_I2C_INT_STA)) { //old
				break;
			}	
	} while((DRV_I2C_ReadReg16(REG_I2C_FIFO_STAT)>>4)&0x0f);
 	// read data
 	i = 0;
 	do{
 		cnt = 100000;
	 	do {
			fifo_sts = DRV_I2C_ReadReg16(REG_I2C_FIFO_STAT);
			cnt --;
		}while((fifo_sts & 0x01 ) && (0 != cnt));
		if (cnt != 0)
		{
			*(pval+i) = DRV_I2C_ReadReg16(REG_I2C_DATA_PORT) & 0xff;
		}
		else
		{
			break;
		}
		i++;
 	}while(num--);
	
	// read Int status 
	#if I2C_PMIC_DRV_TEST
	cnt = i2c_wait_complete_max;//300000 ; 
	#else
	cnt = I2C_WAIT_TIMEOUT;
	#endif
	do
	{
		int_sts = DRV_I2C_ReadReg16(REG_I2C_INT_STA);
		cnt -- ;
	}while(((int_sts & I2C_TRANSAC_COMPLETE) ==0 ) && (0 != cnt));



	if (int_sts == I2C_TRANSAC_COMPLETE)
	{
		ret_sts =  I2C_PASS;
	}
	else
	{
		if (int_sts & I2C_TRANSAC_ACK_ERR)
		{
			ret_sts = I2C_ACKERR;
		}
		else if (int_sts & I2C_HS_NACK_ERR)
		{
			ret_sts = I2C_NACKERR;
		}
		else 
		{
			I2C_PRINT("[I2C_FAIL]READ REG INT STS :%x\r\n ",int_sts);
			ret_sts = I2C_FAIL;
		}
	}
	// power down 
	PDN_SET(PDN_I2C);
	return ret_sts; 
}

I2C_STATUS i2c_pmic_reg_write(kal_uint8 slave_addr ,kal_uint8 reg , kal_uint8 val)
{
	kal_uint32 cnt = 100000;
	kal_uint32 int_sts =0;
	//kal_uint32 fifo_sts = 0;
	I2C_STATUS ret_sts;
 	// Power on I2C
 	PDN_CLR(PDN_I2C);
 	// reset I2C
 	DRV_WriteReg32(REG_I2C_SOFTRESET, 0x01);
 	// set to open-drain mode
 	DRV_WriteReg32(REG_I2C_IO_CONFIG, 0x03);
 	// always enable ack error detection
 	ENABLE_I2C_ACK_ERR_DET; //Always enable ack error detection
 	// always enable nack error detection
 	ENABLE_I2C_NAKERR_DET;  
	// clear FIFO
	CLEAR_I2C_FIFO;
	// clear STA
	CLEAR_I2C_STA;
 	// set slave address
 	slave_addr  = (slave_addr << 1);
 	SET_I2C_SLAVE_ADDRESS(slave_addr , I2C_WRITE_BIT);

	
	i2c_set_speed(FS_300K);
	if (g_i2cCfg.mode == I2C_TRANSACTION_FAST_MODE)
	{// full speed
		SET_I2C_FAST_MODE;
		SET_I2C_STEP_CNT_DIV(g_i2cCfg.step_cnt_div);
		SET_I2C_SAMPLE_CNT_DIV(g_i2cCfg.sample_cnt_div);
		// turn off driving 1
		DRV_WriteReg(REG_I2C_IO_CONFIG,0x03);
	}
	else
	{// high speed
		// set transaction mode 
 		SET_I2C_HS_MODE;
 		// set speed 
 		SET_I2C_HS_STEP_CNT_DIV(g_i2cCfg.step_cnt_div);
		SET_I2C_HS_SAMPLE_CNT_DIV(g_i2cCfg.sample_cnt_div);
 		 // turn on driving 
 	 	DRV_WriteReg(REG_I2C_IO_CONFIG, 0x00);	//turn on driving 1
	}

	// set transfer num
	SET_I2C_TRANSACTION_LENGTH(1);
 	// set transfer length 
 	SET_I2C_TRANSFER_LENGTH(2);

 
	// write reg address 
	DRV_I2C_WriteReg16(REG_I2C_DATA_PORT,reg);
	// write data
	DRV_I2C_WriteReg16(REG_I2C_DATA_PORT,val);
 	// start I2C
 	START_I2C_TRANSACTION;
 
	/*do {
		if(0 == (DRV_I2C_ReadReg16(REG_I2C_START)&0x01)) { //if(0 != DRV_I2C_ReadReg16(REG_I2C_INT_STA)) { //old
			break;
		}
	} while((DRV_I2C_ReadReg16(REG_I2C_FIFO_STAT)>>1)&0x01);*/
	// read Int status 
	#if I2C_PMIC_DRV_TEST
	cnt = i2c_wait_complete_max;//300000 ; 
	#else
	cnt = I2C_WAIT_TIMEOUT;
	#endif
	do
	{
		int_sts = DRV_I2C_ReadReg16(REG_I2C_INT_STA);
		cnt -- ;
	}while(((int_sts & I2C_TRANSAC_COMPLETE) ==0 ) && (0 != cnt));



	if (int_sts == I2C_TRANSAC_COMPLETE)
	{
		ret_sts =  I2C_PASS;
	}
	else
	{
		if (int_sts & I2C_TRANSAC_ACK_ERR)
		{
			ret_sts = I2C_ACKERR;
		}
		else if (int_sts & I2C_HS_NACK_ERR)
		{
			ret_sts = I2C_NACKERR;
		}
		else 
		{
			I2C_PRINT("[I2C_FAIL]WRITE REG INT STS %d\r\n",int_sts);
			ret_sts = I2C_FAIL;
		}
	}
	// power down 
	PDN_SET(PDN_I2C);
	return ret_sts; 
}





#if I2C_PMIC_DRV_TEST

//typedef I2C_REPORT_STATUS (*i2c_testcase_fn_ptr)(kal_uint32 flags, void *param);
typedef I2C_REPORT_STATUS  (*i2c_testcase_fn_ptr)(kal_uint32 flags, void *param);
typedef struct
{
    i2c_testcase_fn_ptr  _main_fn;
    kal_uint32         flags;
    void               *para;
	kal_char           *description;
}i2c_testcase_struct;








#define I2C_PMIC_TESTCASE_REPORT(module, tcs, idx, report)                              \
do{                                                                               \
	I2C_REPORT_STATUS ret;                                                         \
	ret = (tcs)[(idx)]._main_fn(tcs[(idx)].flags, tcs[(idx)].para);               \
	if (I2C_REPORT_PASS == ret)                                                    \
	{                                                                             \
		I2C_PRINT("\r\n^^%s::%s::Pass&&\r\n", module, tcs[(idx)].description);    \
	}                                                                             \
	else if (I2C_REPORT_FAIL == ret)                                               \
	{                                                                             \
		I2C_PRINT("\r\n^^%s::%s::Fail&&\r\n", module, tcs[(idx)].description);    \
		(report) = I2C_REPORT_FAIL;                                                \
	}                                                                             \
	else                                                                          \
	{                                                                             \
	}                                                                             \
}while(0)


#define MT6329_BANK0_SLAVE_ADDR 0x60 //1100000b
#define MT6329_BANK1_SLAVE_ADDR 0x61 //1100001b

#define TEST_LOOP_MAX 1000
//#define SLAVE_ADDR MT6329_BANK1_SLAVE_ADDR
#define NCP6335_SLAVE_ADDR 0x1c
#define NCP6335_RW_REG 0x02
#define NCP6335_RO_REG 0x03
#define SLAVE_ADDR NCP6335_SLAVE_ADDR
#define RW_TEST_REG NCP6335_RW_REG
#define RO_TEST_REG NCP6335_RO_REG
extern void srand(kal_uint32 seed);
extern int  rand(void);

#define MAX_WAIT_COMP_COUNT 1000000
#define FIRST_WAIT_COMP_COUNT 100000
#define WAIT_COMP_COUNT_STEP 50000
I2C_REPORT_STATUS ut_i2c_pmic_wait_comp_count_test(kal_uint32 flags, void *param)
{
	I2C_STATUS sts;
	kal_uint8 data ,data1;
	kal_uint32 i , fail;
	kal_uint32 first_pass_comp_cnt;
	srand(1);
	first_pass_comp_cnt = 0;
	I2C_PRINT("ut_i2c_pmic_wait_comp_count_test begin\r\n");
	for (i2c_wait_complete_max =FIRST_WAIT_COMP_COUNT ;  i2c_wait_complete_max <=MAX_WAIT_COMP_COUNT;i2c_wait_complete_max +=WAIT_COMP_COUNT_STEP)
	{
		I2C_PRINT("test cnt %d\r\n",i2c_wait_complete_max);
		fail = 0;
		for(i = 0 ; i< 10000; i ++)
		{
			data = rand()%0xff;
			sts = i2c_pmic_reg_write(SLAVE_ADDR, RW_TEST_REG, data);
			if (sts != I2C_PASS) {
				I2C_PRINT("i= %d  write err  sts %x , data : %x , cnt %x\r\n",i,sts ,data, i2c_wait_complete_max);
				fail =1;
				break;
			}
			data1 = ~data;
			sts  = i2c_pmic_reg_read(SLAVE_ADDR,RW_TEST_REG,&data1);
			if (sts != I2C_PASS)
			{
				I2C_PRINT("i= %d  read err  sts %x , data : %x , cnt %x\r\n",i,sts ,data1, i2c_wait_complete_max);
				fail =1;
				break;
			}
			if ((data|0x18) != data1){
				I2C_PRINT("i= %d  cmp err  w data %x , r data : %x\r\n",i,data ,data1 );
				fail =1;
				break;
			}
		}
		if (fail ==1){
			I2C_PRINT("test cnt %d  fail \r\n",i2c_wait_complete_max);
		}
		else {
			I2C_PRINT("test cnt %d pass \r\n",i2c_wait_complete_max);
			if (first_pass_comp_cnt ==0)
				first_pass_comp_cnt = i2c_wait_complete_max;
		}
	}
	i2c_wait_complete_max = (first_pass_comp_cnt == 0) ? 300000 : first_pass_comp_cnt;
	I2C_PRINT("use wait complete cnt %d\r\n",i2c_wait_complete_max);
	return I2C_REPORT_PASS;
}

typedef struct {
    /* register offset */
    kal_uint8  regAddr;
    /* r: read only, w: write only, a:readable & writable
     * k: read clear, x: don't care
     * s: readable and write 1 set, c: readable and write 1 clear
     */
    kal_uint8 attribute[32];
    /* 0: default is 0
     * 1: default is 1
     * x: don't care
     */
    kal_uint8 resetVal[32];
} reg_desc_t;
#define PMIC_6335D_INT_ACK 0x0
#define PMIC_6335D_INT_SEN 0x1
#define PMIC_6335D_INT_MSK 0x2
#define PMIC_6335D_PID 0x3
#define PMIC_6335D_RID 0x4
#define PMIC_6335D_FID 0x5
#define PMIC_6335D_PROGVSEL1 0x10
#define PMIC_6335D_PROGVSEL0 0x11
#define PMIC_6335D_PGOOD 0x12
#define PMIC_6335D_TIME 0x13
#define PMIC_6335D_COMMAND 0x14
#define PMIC_6335D_MODULE 0x15
#define PMIC_6335D_LIMCONF 0x16

reg_desc_t pmic6335d_reg[] = {
	{		
		.regAddr=PMIC_6335D_INT_ACK,
		.attribute={"kkkkkkkk"},
		.resetVal={"00000000"}
	},
	{
		.regAddr=PMIC_6335D_INT_SEN,
		.attribute={"rrrrrrrr"},
		.resetVal={"00000000"}
	},
	{
		.regAddr=PMIC_6335D_INT_MSK,
		.attribute={"aaarraaa"},
		.resetVal={"11111111"}
	},
	{
		.regAddr=PMIC_6335D_PID,
		.attribute={"rrrrrrrr"},
		.resetVal={"00001000"}
	
	},
	{
		.regAddr=PMIC_6335D_RID,
		.attribute={"rrrrrrrr"},
		.resetVal={"xxxxxxxx"}
	
	},
	{
		.regAddr=PMIC_6335D_FID,
		.attribute={"rrrrrrrr"},
		.resetVal={"10000000"}
	
	},
	{
		.regAddr=PMIC_6335D_PROGVSEL1,
		.attribute={"aaaaaaaa"},
		.resetVal={"00001011"}
	
	},
	{
		.regAddr=PMIC_6335D_PROGVSEL0,
		.attribute={"aaaaaaaa"},
		.resetVal={"00001011"}
	
	},
	{
		.regAddr=PMIC_6335D_PGOOD,
		.attribute={"aaaaarrr"},
		.resetVal={"00000000"}
	
	},
	{
		.regAddr=PMIC_6335D_TIME,
		.attribute={"aaraaaaa"},
		.resetVal={"10011000"}
	
	},
	{
		.regAddr=PMIC_6335D_COMMAND,
		.attribute={"aaaarrra"},
		.attribute={"arrraaaa"},
		.resetVal={"10000000"}
	
	},
	{
		.regAddr=PMIC_6335D_MODULE,
		.attribute={"rrrraaaa"},
		.resetVal={"00000001"}
	},
	{
		.regAddr=PMIC_6335D_LIMCONF,
		.attribute={"aaaraaaa"},
		.resetVal={"11000110"}
	},
	
};


reg_desc_t pmic6335f_reg[] = {
	{		
		.regAddr=PMIC_6335D_INT_ACK,
		.attribute={"kkkkkkkk"},
		.resetVal={"00000000"}
	},
	{
		.regAddr=PMIC_6335D_INT_SEN,
		.attribute={"rrrrrrrr"},
		.resetVal={"00000000"}
	},
	{
		.regAddr=PMIC_6335D_INT_MSK,
		.attribute={"aaarraaa"},
		.resetVal={"11111111"}
	},
	{
		.regAddr=PMIC_6335D_PID,
		.attribute={"rrrrrrrr"},
		.resetVal={"00001000"}
	
	},
	{
		.regAddr=PMIC_6335D_RID,
		.attribute={"rrrrrrrr"},
		.resetVal={"xxxxxxxx"}
	
	},
	{
		.regAddr=PMIC_6335D_FID,
		.attribute={"rrrrrrrr"},
		.resetVal={"00000000"}
	
	},
	{
		.regAddr=PMIC_6335D_PROGVSEL1,
		.attribute={"aaaaaaaa"},
		.resetVal={"00011011"}
	
	},
	{
		.regAddr=PMIC_6335D_PROGVSEL0,
		.attribute={"aaaaaaaa"},
		.resetVal={"00100011"}
	
	},
	{
		.regAddr=PMIC_6335D_PGOOD,
		.attribute={"aaaaarrr"},
		.resetVal={"00000000"}
	
	},
	{
		.regAddr=PMIC_6335D_TIME,
		.attribute={"aaraaaaa"},
		.resetVal={"10011000"}
	
	},
	{
		.regAddr=PMIC_6335D_COMMAND,
		.attribute={"aaaarrra"},
		.attribute={"arrraaaa"},
		.resetVal={"10000010"}
	
	},
	{
		.regAddr=PMIC_6335D_MODULE,
		.attribute={"rrrraaaa"},
		.resetVal={"00000001"}
	},
	{
		.regAddr=PMIC_6335D_LIMCONF,
		.attribute={"aaaraaaa"},
		.resetVal={"11000111"}
	},
	
};


I2C_REPORT_STATUS ut_i2c_pmic6335_reg_access_test(kal_uint32 flags, void *param)
{
	kal_int32 regIdx,bitIdx ,reg_num;
	kal_uint8 regVal ,testVal ,tmpVal,val[3];
	I2C_STATUS sts;
	I2C_REPORT_STATUS ut_ret_status;
	reg_desc_t * reg_table;
		// check register initial value
	if ((flags &0x1) ==0) {
		reg_table = pmic6335f_reg;
		reg_num = (sizeof(pmic6335f_reg)/sizeof(reg_desc_t));
	}
	else
	{
		reg_table = pmic6335d_reg;
		reg_num = (sizeof(pmic6335d_reg)/sizeof(reg_desc_t));
	}
	/*sts = i2c_pmic_reg_write(SLAVE_ADDR,0x12,0);
	sts = i2c_pmic_reg_write(SLAVE_ADDR,0x13,0);
	sts = i2c_pmic_reg_read(SLAVE_ADDR,0x12, &regVal);
	I2C_PRINT("read 0x12 = %d",regVal);
	sts = i2c_pmic_reg_read_more(SLAVE_ADDR,0x12,val,2);
	I2C_PRINT("Read more sts %d val[0] val[1]\r\n",sts,val[0],val[1]);*/

	/*sts = i2c_pmic_reg_write(0x61,0x24,0);
	sts = i2c_pmic_reg_write(0x61,0x25,0);
	sts = i2c_pmic_reg_read(0x61,0x24, &regVal);
	I2C_PRINT("read 0x12 = %d",regVal);
	sts = i2c_pmic_reg_read_more(0x61,0x24,val,2);
	I2C_PRINT("slave %x Read more sts %d val[0] val[1]\r\n",0x61,sts,val[0],val[1]);
	*/
	I2C_PRINT("Test ut_i2c_pmic6335_reg_access_test\r\n");
	for (regIdx = reg_num - 1; regIdx >= 0; regIdx--) {
		for (bitIdx = 7; bitIdx >= 0; bitIdx--) {
			if (('w' != reg_table[regIdx].attribute[bitIdx]) && ('x' != reg_table[regIdx].resetVal[bitIdx])) {
				sts = i2c_pmic_reg_read(SLAVE_ADDR,reg_table[regIdx].regAddr , &regVal);
				if (sts != I2C_PASS){
					I2C_PRINT("Read reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
					return I2C_REPORT_FAIL;
				}
				regVal = (regVal >> bitIdx) & 0x01;
				if (regVal != (reg_table[regIdx].resetVal[bitIdx] - '0')) {
					I2C_PRINT( "Incorrect Initial Register Reset Value at %x (bit %d exp %d real %d).\r\n",
						(kal_uint32)reg_table[regIdx].regAddr, bitIdx,
						reg_table[regIdx].resetVal[bitIdx] - '0', regVal);
					ut_ret_status = I2C_REPORT_FAIL;
				}
			}
		}
	}
	// ReadOnly Register Test
	for (regIdx = reg_num - 1; regIdx >= 0; regIdx--) {
		for (bitIdx = 7; bitIdx >= 0; bitIdx--) {
			if (('r' == reg_table[regIdx].attribute[bitIdx]) && ('x' != reg_table[regIdx].resetVal[bitIdx])) {
				sts = i2c_pmic_reg_read(SLAVE_ADDR,reg_table[regIdx].regAddr , &tmpVal);
				if (sts != I2C_PASS){
					I2C_PRINT("Read reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
					return I2C_REPORT_FAIL;
				}
                            regVal = (tmpVal >> bitIdx) & 0x01;
                    	       testVal = (regVal == 0) ? (tmpVal | (0x1 << bitIdx)) : (tmpVal & (~(0x1 << bitIdx)));
            	              sts  = i2c_pmic_reg_write(SLAVE_ADDR,reg_table[regIdx].regAddr,testVal);
				if (sts != I2C_PASS)
				{
					I2C_PRINT("write reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
					return I2C_REPORT_FAIL;
				}
				sts = i2c_pmic_reg_read(SLAVE_ADDR,reg_table[regIdx].regAddr , &tmpVal);
				if (sts != I2C_PASS){
					I2C_PRINT("Read reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
					return I2C_REPORT_FAIL;
				}
				regVal = (tmpVal >> bitIdx) & 0x01;
				if (regVal == ((testVal >> bitIdx) & 0x01)) {
					I2C_PRINT("Incorrect ReadOnly Register Value at %x (bit %d exp %d real %d).\r\n",
						(kal_uint32)reg_table[regIdx].regAddr, bitIdx,
						(~regVal & 0x1), regVal);
					ut_ret_status = I2C_REPORT_FAIL;
				}
			}
		}
	}

	// Readable&Writeable Register Test
	for (regIdx = reg_num - 1; regIdx >= 0; regIdx--) {
		for (bitIdx = 7; bitIdx >= 0; bitIdx--) {
			if (('a' == reg_table[regIdx].attribute[bitIdx]) && ('x' != reg_table[regIdx].resetVal[bitIdx])) {
				for (testVal = 0; testVal <=1; testVal++) {
////testVal = 0x1 - ((DRV_Reg32(reg_table[regIdx].regAddr) >> bitIdx) & 0x00000001);
					sts  = i2c_pmic_reg_write(SLAVE_ADDR,reg_table[regIdx].regAddr,testVal << bitIdx);
					if (sts != I2C_PASS)
					{
						I2C_PRINT("write reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
						return I2C_REPORT_FAIL;
					}
					sts = i2c_pmic_reg_read(SLAVE_ADDR,reg_table[regIdx].regAddr , &tmpVal);
					if (sts != I2C_PASS){
						I2C_PRINT("Read reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
						return I2C_REPORT_FAIL;
					}
					regVal = (tmpVal >> bitIdx) & 0x01;
					if (regVal != testVal) {
						I2C_PRINT("Incorrect Readable&Writeable Register Value at %x(bit %d exp %d real %d).\r\n",
							(kal_uint32)reg_table[regIdx].regAddr, bitIdx, testVal, regVal);
						ut_ret_status = I2C_REPORT_FAIL;
					}
				}
			}
		}
	}

	// Readable&Write 1 clear Register Test
	for (regIdx = reg_num - 1; regIdx >= 0; regIdx--) {
		for (bitIdx = 7; bitIdx >= 0; bitIdx--) {
			if (('c' == reg_table[regIdx].attribute[bitIdx]) && ('x' != reg_table[regIdx].resetVal[bitIdx])) {
				testVal = 1;

				sts  = i2c_pmic_reg_write(SLAVE_ADDR,reg_table[regIdx].regAddr,testVal << bitIdx);
				if (sts != I2C_PASS)
				{
					I2C_PRINT("write reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
					return I2C_REPORT_FAIL;
				}
				sts = i2c_pmic_reg_read(SLAVE_ADDR,reg_table[regIdx].regAddr , &tmpVal);
				if (sts != I2C_PASS){
					I2C_PRINT("Read reg %x fail ,sts %d\r\n",reg_table[regIdx].regAddr,sts);
					return I2C_REPORT_FAIL;
				}
				
				regVal = ( tmpVal>> bitIdx) & 0x01;
                            testVal = 0;
				if (regVal != testVal) {
					I2C_PRINT("Incorrect Readable&Write 1 Clear  Register Value at %x (bit %d exp %d real %d).\r\n",
						(kal_uint32)reg_table[regIdx].regAddr, bitIdx, testVal, regVal);
					ut_ret_status = I2C_REPORT_FAIL;
				}
			}
		}
	}
	I2C_PRINT("Test ut_i2c_pmic6335_reg_access_test Finish ut_sts %d\r\n",ut_ret_status);
	return ut_ret_status;
}

I2C_REPORT_STATUS ut_i2c_pmic_loopback_test(kal_uint32 flags, void *param)
{ // write then read 
	I2C_STATUS sts;
	kal_uint8 data;
	kal_uint8 data1;
	kal_uint32 i ;
	srand(1);
	I2C_PRINT("test ut_i2c_pmic_loopback_test\r\n");
	for (i =0; i < TEST_LOOP_MAX;i++)
	{
		//sts = i2c_pmic_reg_read(SLAVE_ADDR,RW_TEST_REG,&data);
		//I2C_PRINT("slave addr %x reg %x data %x sts %x\r\n",SLAVE_ADDR,RW_TEST_REG,data,sts);
		//sts = i2c_pmic_reg_read(SLAVE_ADDR,0x3,&data);
		//I2C_PRINT("slave addr %x reg %x data %x sts %x\r\n",SLAVE_ADDR,0x3,data,sts);
		//sts = i2c_pmic_reg_read(SLAVE_ADDR,0x4,&data);
		//I2C_PRINT("slave addr %x reg %x data %x sts %x\r\n",SLAVE_ADDR,0x4,data,sts);
		
	 	data = rand()%0xff;
	 	//data =0x00;
		data1 = ~data;
		sts = i2c_pmic_reg_write(SLAVE_ADDR, RW_TEST_REG, data);
		if (sts != I2C_PASS) {
			I2C_PRINT("i= %d  write err  sts %x , data : %x\r\n",i,sts ,data );
			return I2C_REPORT_FAIL;
		}

		sts = i2c_pmic_reg_read(SLAVE_ADDR,RW_TEST_REG, &data1);
		if (sts != I2C_PASS) {
			I2C_PRINT("i= %d  read err  sts %x , data : %x\r\n",i,sts ,data1 );
			return I2C_REPORT_FAIL;
		}
		if ((data|0x18) != data1){
			I2C_PRINT("i= %d  cmp err  w data %x , r data : %x\r\n",i,data ,data1 );
			return I2C_REPORT_FAIL;
		}
			
	}
	I2C_PRINT("test ut_i2c_pmic_loopback_test pass\r\n");
	return I2C_REPORT_PASS;
}
 I2C_REPORT_STATUS ut_i2c_pmic_readonly_reg_test (kal_uint32 flags, void *param)
{ // write read only then read 
	I2C_STATUS sts;
	kal_uint8 data;
	kal_uint8 data1;
	kal_uint8 data2;
	kal_uint32 i ; 
	srand(1);
	I2C_PRINT("test ut_i2c_pmic_readonly_reg_test\r\n");
	for (i =0 ;i < TEST_LOOP_MAX;i++)
	{
		sts = i2c_pmic_reg_read(SLAVE_ADDR,RO_TEST_REG, &data1);
		if (sts != I2C_PASS) {
			I2C_PRINT("i= %d  read err  sts %x , data : %x\r\n",i,sts ,data1 );
			return I2C_REPORT_FAIL;
		}
		do{
	 		data = rand()%0xff;
		}while(data == data2);
		data =0xff;
		//data1 = ~data;
		sts = i2c_pmic_reg_write(SLAVE_ADDR, RO_TEST_REG, data);
		if (sts != I2C_PASS) {
			I2C_PRINT("i= %d  write err  sts %x , data : %x\r\n",i,sts ,data );
			return I2C_REPORT_FAIL;
		}

		sts = i2c_pmic_reg_read(SLAVE_ADDR,RO_TEST_REG, &data2);
		if (sts != I2C_PASS) {
			I2C_PRINT("i= %d  read err  sts %x , data : %x\r\n",i,sts ,data2);
			return I2C_REPORT_FAIL;
		}

		if (data2 != data1)
		{
			I2C_PRINT("i= %d  cmp err  r data1 %x ,w data %x r data2 : %x\r\n",i,data1,data,data2);
			return I2C_REPORT_FAIL;
		}
			
	}
	I2C_PRINT("test ut_i2c_pmic_readonly_reg_test pass\r\n");
	return I2C_PASS;
}
I2C_REPORT_STATUS ut_i2c_pmic_unexist_slave_addr_test(kal_uint32 flags, void *param)
{ // will unexist slave address
	I2C_STATUS sts;
	kal_uint8 data;
	kal_uint8 data1;
	kal_uint8 unexist_slave_addr;

	kal_uint32 i ; 
	I2C_PRINT("test ut_i2c_pmic_unexist_slave_addr_test\r\n");
	srand(1);
	for (i =0; i < TEST_LOOP_MAX;i++)
	{


		do{
	 		unexist_slave_addr = (kal_uint8)(rand()%0x7f);
		}while(unexist_slave_addr == SLAVE_ADDR);
		data = 0xf0;
		sts = i2c_pmic_reg_write(unexist_slave_addr, RW_TEST_REG, data);
		if (sts != I2C_ACKERR)
		{
			I2C_PRINT("i= %d  write err  sts %x , slave addr %x\r\n",i,sts,unexist_slave_addr);
			return I2C_REPORT_FAIL;
		}
		sts = i2c_pmic_reg_read(unexist_slave_addr,RW_TEST_REG, &data1);
		if (sts != I2C_ACKERR)
		{
			I2C_PRINT("i= %d  read err  sts %x , slave addr %x\r\n",i,sts,unexist_slave_addr);
			return I2C_REPORT_FAIL;
		}

			
	}
	I2C_PRINT("test ut_i2c_pmic_unexist_slave_addr_test pass\r\n");
	return I2C_REPORT_FAIL;
}



#endif

#else
// not mt6290 
#include "i2c_pmic.h"

I2C_STATUS i2c_pmic_reg_read(kal_uint8 slave_addr , kal_uint8 reg , kal_uint8 * pval)
{
	return I2C_FAIL;
}

I2C_STATUS i2c_pmic_reg_write(kal_uint8 slave_addr ,kal_uint8 reg , kal_uint8 val)
{
	return I2C_FAIL;
}


#endif 







