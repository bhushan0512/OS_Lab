#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(pid==-1)
    {
        printf("error:failed to create child \n");
    }
    else if(pid==0)
    {
        printf("child process");
    }
    else
    {
        printf("parent process \n");
    }
    return 0;
}
