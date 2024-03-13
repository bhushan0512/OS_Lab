#include <stdio.h>

void main(){
    int at[10] = {0}, bt[10] = {0}, ct[10] = {0}, tat[10] = {0}, wt[10] = {0}, remaining_burst[10];
    int n = 10, time = 0, smallest, count = 0;
    float totalTAT, totalWT;

    printf("Enter number of process:");
    scanf("%d", &n);

    print("Enter the arrival time and burst time fo each process\n\n");

    for (int i = 0 ; i <n; i++){
        
        printf("\n\nEnter the Arrival time of process[%d]: ", i+1);
        scanf("%d",at[i]);

        printf("\nEnter the Burst time of process[%d]: ", i+1);
        scanf("%d",bt[i]);

        remaining_burst[i] = bt[i];
    }

    while (count<n){
        smallest = -1;

        for (int i = 0; i < n; i++){
            if (at[i]<=time && remaining_burst[i] >0)
            {
                /* code */
            }
            
        }
        
    }
    
    
}