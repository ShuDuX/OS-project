#include "ipc.h"
int main(int argc,char *argv[])
{
	int rate;
	if(argv[1] != NULL) rate = atoi(argv[1]);
	else rate = 3; 
	buff_key = 1001; 
	buff_num = 3;
	pput_key = 1002;
	pput_num = 1; 
	shm_flg = IPC_CREAT | 0644;
	buff_ptr = (char *)set_shm(buff_key,buff_num,shm_flg);
	pput_ptr = (int *)set_shm(pput_key,pput_num,shm_flg);
	prod_key = 2001; 
	pmtx_key = 2002; 
	cons_key_1 = 3001; 
	cons_key_2 = 3002;
	cons_key_3 = 3003;
	cmtx_sem = 3004;
	sem_flg = IPC_CREAT | 0644; 
	sem_val = 1;//only put once
	prod_sem = set_sem(prod_key,sem_val,sem_flg);
	sem_val = 0;
	cons_sem_1 = set_sem(cons_key_1,sem_val,sem_flg);
	cons_sem_2 = set_sem(cons_key_2,sem_val,sem_flg);
	cons_sem_3 = set_sem(cons_key_3,sem_val,sem_flg);
	sem_val = 1;
	pmtx_sem = set_sem(pmtx_key,sem_val,sem_flg);
	while(1)
	{	
		int r=rand()%3;
		if(r==0)
		{
		down(prod_sem);
		down(pmtx_sem);
		buff_ptr[*pput_ptr]='p';
		buff_ptr[*pput_ptr+1]='g';
		sleep(rate);
		printf("%dproducer put :paper(%c),glue(%c)\n",getpid(),buff_ptr[*pput_ptr],buff_ptr[*pput_ptr+1]);
		up(pmtx_sem);
		up(cons_sem_1);
		}
		else if(r==1)
		{
		down(prod_sem);
		down(pmtx_sem);
		buff_ptr[*pput_ptr+2]='t';
		buff_ptr[*pput_ptr+1]='g';
		sleep(rate);
		printf("%dproducer put :tobacco(%c),glue(%c)\n",getpid(),buff_ptr[*pput_ptr+2],buff_ptr[*pput_ptr+1]);
		up(pmtx_sem);
		up(cons_sem_2);
		}
		else if(r==2)
		{
		down(prod_sem);
		down(pmtx_sem);
		buff_ptr[*pput_ptr+2]='t';
		buff_ptr[*pput_ptr]='p';
		sleep(rate);
		printf("%dproducer put :tobacco(%c),paper(%c)\n",getpid(),buff_ptr[*pput_ptr+2],buff_ptr[*pput_ptr]);
		up(pmtx_sem);
		up(cons_sem_3);
		}
	}
}
