#ifndef PETERSSON_LOCK_H
#define PETERSSON_LOCK_H


/* the instance must be non-cache type */
typedef struct _petersonslock {
    volatile kal_uint32 flag[2];
    volatile kal_uint32 turn;
} petersonslock_t;

//#define P_INIT_KEY 0xBABEFAC0

void p_lock_init(petersonslock_t *l);
kal_bool p_lock_acquire(petersonslock_t *l, kal_uint32 id, kal_uint32 timeout);
void p_lock_release(petersonslock_t *l, kal_uint32 id);

#endif /*PETERSSON_LOCK_H*/
