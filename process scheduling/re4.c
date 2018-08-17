/*
*/
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
typedef void (*sighandler_t)(int);
int main(int argc,char* argv[])
{
	int pid;
	int pid1=getpid();
	int sch1=0,sch2=0;
	int i=0;
	void sigcat1()
	{
         if(pid==0)
	 {
	  ++sch1;
          setpriority(PRIO_PROCESS,pid,sch1);
	 }
	}
	void sigcat2()
	{
	 --sch2;
      	 setpriority(PRIO_PROCESS,pid1,sch2);
        }
	signal(SIGINT,(sighandler_t)sigcat1);
	signal(SIGTSTP,(sighandler_t)sigcat2);
	pid=fork();
	sch1=getpriority(PRIO_PROCESS,pid);
	sch2=getpriority(PRIO_PROCESS,pid1);
	if(pid<0)
	{
	   printf("子进程创建失败！\n");
	   exit(1);
	}
	while(i<10){
	if(pid==0)
	{
	  printf("I am child,my pid is %d (policy = %d )\n",getpid(),sched_getscheduler(getpid()));
	  printf("The child`s priority is %d\n",getpriority(PRIO_PROCESS,getpid()));
	  kill(getppid(),SIGTSTP);
	  i++;
	  sleep(1);
	}
	else
	{
	  printf("I am father,my pid is %d (policy = %d )\n",getpid(),sched_getscheduler(getpid()));
 	  printf("The father`s priority is %d\n",getpriority(PRIO_PROCESS,getpid()));
	  kill(pid,SIGINT);
	  i++;
	  sleep(1);
	}
	}
	return 0;
}
