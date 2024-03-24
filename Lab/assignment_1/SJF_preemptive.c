#include <stdio.h>

void main()
{
    int bt[10] = {0}, at[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0}, remaining_burst[10];
    int n, time = 0, smallest, count = 0, current_process = -1;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process\n\n");

    for (int i = 0; i < n; i++){

        printf("Arrival time of process[%d] ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d] ", i + 1);
        scanf("%d", &bt[i]);

        remaining_burst[i] = bt[i];

        printf("\n");
    }

    while (count < n){
        smallest = -1;

        for (int i = 0; i < n; i++){
            if (at[i] <= time && remaining_burst[i] > 0)
                if (smallest == -1 || remaining_burst[i] < remaining_burst[smallest])
                    smallest = i;
            
        }
        if (smallest == -1)
            time++;
        else{
            if (current_process != -1 && remaining_burst[current_process] > 0 && remaining_burst[smallest] < remaining_burst[current_process]){
                ct[current_process] = time;
                current_process = smallest;
            }
            else if (current_process == -1)
                current_process = smallest;

            remaining_burst[smallest]--;
            time++;

            if (remaining_burst[smallest] == 0){
                count++;
                ct[smallest] = time;
                tat[smallest] = ct[smallest] - at[smallest];
                wt[smallest] = tat[smallest] - bt[smallest];

                totalTAT += tat[smallest];
                totalWT += wt[smallest];

                current_process = -1;
            }
        }
    }

    printf("Solution: \n\n");
    printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\n\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("Average WT = %.2f\n\n", totalWT / n);
}