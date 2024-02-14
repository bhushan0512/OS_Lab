#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

//getpid->child process
//getpid->parent process


void main(){
	for(int i=0;i<5;i++)
	{
		if(fork()==0){
			printf("\n[son]pid %d from [parent] pid %d\n",getpid(),getppid());
			exit(0);
		}
	}
	for(int i=0;i<5;i++)
		wait(NULL);
			
	//printf("\n\n\n\nCHILD PROCESS ID: %d\n",getppid());
}
