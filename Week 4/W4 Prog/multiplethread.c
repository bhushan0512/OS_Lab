#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *fun(void* args)
{
int b=pthread_self();
printf("Inside the thread:%d\n",b);
for(int i=0;i<10;i++)
{
printf("%d\t",i);
}
pthread_exit(NULL);
}

void main()
{
pthread_t p_id;
pthread_create(&p_id,NULL,&fun,NULL);
pthread_join(p_id,NULL);
int p=pthread_self();

printf("\nThread ended %d\n",p);
pthread_exit(NULL);
}
