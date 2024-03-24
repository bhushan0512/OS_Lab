#include<stdio.h>
#include<unistd.h>

int main()
{
    int n,i,result=1;
    printf("enter the value of n:");
    scanf("%d",&n);
    pid_t pid=fork();
    if(pid==0)
    {
        for(int i=1;i<=n;i++)
        {
            result*=2;
        }
        printf("child process:2^%d=%d\n",n,result);
        for(i=1;i<=result;i++)
        {
            printf("\n hello\n");
        }
    }
    else if(pid>0)
    {
        printf("parent process:child PID=%d\n",pid);
    }
    else
    {
        printf("fork failed!\n");
        return 1;
    }
    return 0;
    }
