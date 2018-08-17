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
         //if(pid==0)
	 //{
	 ++sch1;
	 ++sch2;
	 //printf("**%d %d**!%d",sch1,getpid(),i);
         setpriority(PRIO_PROCESS,pid,sch1);
	 setpriority(PRIO_PROCESS,pid1,sch2);
	 //}
	// else
	 //{
		//sleep(1);//kill(pid,SIGINT);
	 // printf("------------");}
	}
	void sigcat2()
	{
	// if(pid!=0)
	// {
	 --sch2;
	 --sch1;
      	 setpriority(PRIO_PROCESS,pid1,sch2);
	 setpriority(PRIO_PROCESS,pid,sch1);
	// }
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
	//while(i<10){
	if(pid==0)
	{
	 // signal(SIGINT,(sighandler_t)sigcat1);
	  while(i<15){
	  printf("I am child,my pid is %d (policy = %d )\n",getpid(),sched_getscheduler(getpid()));
	  printf("The child`s priority is %d\n",getpriority(PRIO_PROCESS,getpid()));
	  //kill(getppid(),SIGTSTP);
	    i++;
	  pause();
	  printf("efgh");
	  }
	 exit(EXIT_SUCCESS);
	}
	else
	{
	  //signal(SIGTSTP,(sighandler_t)sigcat2);
	  while(i<15){
	  printf("I am father,my pid is %d (policy = %d )\n",getpid(),sched_getscheduler(getpid()));
 	  printf("The father`s priority is %d\n",getpriority(PRIO_PROCESS,getpid()));
	  //kill(pid,SIGINT);
	    i++;
	  pause();
	  printf("abcd");
	  }
	}
	//}
	return 0;
}
