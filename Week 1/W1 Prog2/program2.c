#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid, child_pid;
    pid=getpid();
    printf("parent process id:%d\n",pid);
    child_pid=fork();
    if(child_pid==0)
    {
        pid=getpid();
        printf("child process id:%d\n",pid);
    }
    else
    {
        printf("parent process id:%d\n",pid);
    }
    return 0;
}
