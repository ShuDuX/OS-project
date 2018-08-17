/*
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/msg.h>
#define BUFSZ 256
//建立获取ipc一组函数的原型说明 
int get_ipc_id(char* proc_file,key_t key);//获取ipc的id号 proc_file ipc相关指令 key id号的键值
char* set_shm(key_t shm_key,int shm_num,int shm_flag);
int set_msq(key_t msq_key,int msq_flag);
int set_sem(key_t sem_key,int sem_val,int sem_flag);
int down(int sem_id);
int up(int sem_id);
//信号灯控制的共同体
typedef union semuns{

	int val;
}Sem_uns;
//消息结构体
typedef struct msgbuf{

	long mtype;
	char mtex[1];
}Msg_buf;
//生产者消费者共享缓冲区
key_t buff_key;
int buff_num;
char* buff_ptr;
//生产者放产品位置的共享指针
key_t pput_key;
int pput_num;
int *pput_ptr;
//消费者取产品的共享指针
key_t cget_key;
int cget_num;
int* cget_ptr;
//生产者有关的信号量
key_t prod_key;
key_t pmtx_key;
int prod_sem;
int pmtx_sem;
//消费者有关的信号量
key_t cons_key_1;
key_t cmtx_key;
int cons_sem_1;
int cmtx_sem;
key_t cons_key_2;
int cons_sem_2;
key_t cons_key_3;
int cons_sem_3;

int sem_val;
int sem_flg;
int shm_flg;



