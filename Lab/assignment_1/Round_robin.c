#include <stdio.h>

int main() {
    int bt[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0}, process_no[10];
    int n, time_quantum, remaining_burst[10];
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    printf("Enter burst time for each process\n\n");

    for(int i = 0; i < n; i++) {
        process_no[i] = i + 1;

        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);

        remaining_burst[i] = bt[i];

        printf("\n");
    }

    printf("Processes entered successfully\n");

    int flag = 0;
    int current_time = 0;
    while (1) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                flag = 1;
                if (remaining_burst[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining_burst[i] -= time_quantum;
                } else {
                    current_time += remaining_burst[i];
                    remaining_burst[i] = 0;
                    ct[i] = current_time;
                    tat[i] = ct[i];
                    wt[i] = tat[i] - bt[i];

                    totalTAT += tat[i];
                    totalWT += wt[i];
                }
            }
        }
        if (flag == 0) break;
    }

    printf("Solution: \n\n");
    printf("P#\t BT\t CT\t TAT\t WT\t\n\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\n", process_no[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time = %f\n", totalTAT / n);
    printf("Average WT = %f\n\n", totalWT / n);
}