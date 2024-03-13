#include<stdio.h>
void main(){
    int at[10]={0},bt[10]={0},ct[10]={0},tat[10]={0},wt[10]={0},process_no[10];
    int n,sum=0,temp;
    float totalTAT,totalWT;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the Arrival Time and Burst Time of each processes : \n");
    for(int i=0;i<n;i++){

        process_no[i]=i+1;

        printf("Enter the Arrival Time of process [%d] : ",i+1);
        scanf("%d",&at[i]);

        printf("Enter the Burst Time of process [%d] : ",i+1);
        scanf("%d",&bt[i]);
    }

    //Sorting based on Arrival Time
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){

                //Sort Arrival Time
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                //Sort Burst Time based on Arrival Time
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                //Sort Process Number based on Arrival Time
                temp=process_no[j];
                process_no[j]=process_no[j+1];
                process_no[j+1]=temp;
            }
        }
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
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",process_no[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    float avgTAT = totalTAT/n, avgWT = totalWT/n;
    printf("\nAverage TAT = %f",avgTAT);
    printf("\nAverage WT = %f\n\n",avgWT);
}
