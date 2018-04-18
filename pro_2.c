/*
*
*
*
*
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

//线程执行函数定义
void task1(int*);
void task2(int*);
void task3(int*);

int pipe1[2],pipe2[2],pipe3[2],pipe4[2];
pthread_t thrd1,thrd2,thrd3;
int main()
{

	int ret;
	int num1,num2,num3;
	if(pipe(pepe1)<0)
	{perror("pipe1 not create.");
	 exit(EXIT_FAILURE);
	}	
	if(pipe(pepe2)<0)
	{perror("pipe2 not create.");
	 exit(EXIT_FAILURE);
	}	
	if(pipe(pepe3)<0)
	{perror("pipe3 not create.");
	 exit(EXIT_FAILURE);
	}
	if(pipe(pepe4)<0)
	{perror("pipe4 not create.");
	 exit(EXIT_FAILURE);
	}		
	num1=num2=num3=1;
	ret = pthread_create(&thrd1,NULL,(void*)task1,(void*)&num1);
	if(ret)
	{
	 perror("pthread_create:task1");
	 exit(EXIT_FAILURE);
	}
	ret = pthread_create(&thrd2,NULL,(void*)task2,(void*)&num2);
	if(ret)
	{
	 perror("pthread_create:task2");
	 exit(EXIT_FAILURE);
	}
	ret = pthread_create(&thrd3,NULL,(void*)task3,(void*)&num3);
	if(ret)
	{
	 perror("pthread_create:task3");
	 exit(EXIT_FAILURE);
	}
	//挂起线程
	pthread_join(thrd3,NULL);
	pthread_join(thrd2,NULL);
	pthread_join(thrd1,NULL);

}
void task1(int *num)
{
	int x=1;
	do{
	   printf("thread1 read:%d\n",x++);
	   write(pipe1[1],&x,sizeof(int));
	   read(pipe2[0],&x,sizeof(int))


	}while(x<=9);
	close(pipe1[1]);
	close(pipe2[0]);
}
void task2(int *num)
{
	int x=1;
	do{
	   printf("thread2 read:%d\n",x++);
	   write(pipe4[1],&x,sizeof(int));
	   read(pipe3[0],&x,sizeof(int))


	}while(x<=9);
	close(pipe4[1]);
	close(pipe3[0]);
}
void task3(int *num)
{
	int x=1;
	do{
	   read(pipe1[0],&x,sizeof(int));
	   read(pipe4[0],&x,sizeof(int));
	   printf("thread3 write:%d\n",x++);
	   write(pipe4[1],&x,sizeof(int));
	   read(pipe3[0],&x,sizeof(int))


	}while(x<=9);
	close(pipe4[1]);
	close(pipe3[0]);
	close(pipe2[0]);
	close(pipe1[1]);
}
