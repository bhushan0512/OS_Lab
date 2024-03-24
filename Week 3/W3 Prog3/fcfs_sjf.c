#include<stdio.h>

void main()
{
int n,bt[10],wt[10],tat[20],p[20],i,j,total=0,pos,temp,choice;
float avg_wt,avg_tat;
printf("enter num of process:");
scanf("%d",&n);

printf("enter brust time\n");
for(i=0;i<n;i++)
{
printf("p%d:",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}

printf("enter your choice:");
printf("\n1 sjf \n2 fcfs \n3 exit \n");
scanf("%d",&choice);

switch(choice)
{
case 1:for(i=0;i<n;i++)
{
pos=i;

for(j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
pos=j;
}

temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;

temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
break;

case 2:printf("this is fcfs\n");
break;

case 3:exit(0);
break;
}

wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;

for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}

avg_wt=(float)total/n;
total=0;

printf("process\t brusttime\t wt\t tat");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\n p%d\t %d\t %d\t %d",p[i],bt[i],wt[i],tat[i]);
}

avg_tat=(float)total/n;
printf("\n avg wt=%f",avg_wt);
printf("\n avg tat=%f",avg_tat);
}
