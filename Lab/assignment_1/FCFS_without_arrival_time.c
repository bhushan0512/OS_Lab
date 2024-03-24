#include<stdio.h>
void main(){
    int at[10]={0},bt[10]={0},ct[10]={0},tat[10]={0},wt[10]={0};
    int n,sum=0,temp;
    float totalTAT,totalWT;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the Burst Time of each processes : \n");
    for(int i=0;i<n;i++){
        printf("Enter the Burst Time of process [%d] : ",i+1);
        scanf("%d",&bt[i]);
    }

    //Calculate Completeion Time
    for(int j=0;j<n;j++){
        sum+=bt[j];
        ct[j]+=sum;
    }

    //Calculate Turn Around Time
    for(int k=0;k<n;k++){
        tat[k]=ct[k]-at[k];
        totalTAT+=tat[k];
    }

    //Calculate Waiting Time
    for(int k=0;k<n;k++){
        wt[k]=tat[k]-bt[k];
        totalWT+=wt[k];
    }

    printf("Solutions : \n");
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }


    printf("\nAverage TAT = %f",totalTAT/n);
    printf("\nAverage WT = %f\n\n",totalWT/n);
}
