#include "ipc.h"
int main(int argc,char *argv[])
{
	int rate;
	if(argv[1] != NULL) rate = atoi(argv[1]);
	else rate = 3; 
	buff_key = 1001; 
	buff_num = 3;
	cget_key = 1003; 
	cget_num = 1;
	shm_flg = IPC_CREAT | 0644;
	buff_ptr = (char *)set_shm(buff_key,buff_num,shm_flg);
	cget_ptr = (int *)set_shm(cget_key,cget_num,shm_flg);
	prod_key = 2001; 
	pmtx_key = 2002; 
	cons_key_1 = 3001; 
	cons_key_2 = 3002;
	cons_key_3 = 3003;
	cmtx_sem = 3004;
	sem_flg = IPC_CREAT | 0644; 
	sem_val = 1;
	prod_sem = set_sem(prod_key,sem_val,sem_flg);
	sem_val = 0;
	cons_sem_1 = set_sem(cons_key_1,sem_val,sem_flg);
	cons_sem_2 = set_sem(cons_key_2,sem_val,sem_flg);
	cons_sem_3 = set_sem(cons_key_3,sem_val,sem_flg);
	sem_val = 1;
	cmtx_sem = set_sem(cmtx_key,sem_val,sem_flg);
	while(1)
	{
		down(cons_sem_1);
		down(cmtx_sem);
		sleep(rate);
		printf("%dsmoker get:paper(%c),glue(%c)\n",getpid(),buff_ptr[*cget_ptr],buff_ptr[*cget_ptr+1]);
		up(cmtx_sem);
		up(prod_sem);
	}
	return EXIT_SUCCESS;
}

