#include <stdio.h>

void main() {
    int bt[10] = {0}, at[10] = {0}, priority[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0},remaining_burst[10];
    int n, time = 0, highest_priority, count = 0;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time, and priority for each process\n\n");

    for(int i = 0; i < n; i++) {
        printf("Arrival time of process[%d] ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d] ", i + 1);
        scanf("%d", &bt[i]);

        printf("Priority of process[%d] ", i + 1);
        scanf("%d", &priority[i]);

        remaining_burst[i] = bt[i];
        printf("\n");
    }

    while (count < n) {
        highest_priority = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining_burst[i] > 0) {
                if (highest_priority == -1 || priority[i] < priority[highest_priority]) {
                    highest_priority = i;
                }
            }
        }

        if (highest_priority == -1) {
            time++;
        } else {
            time += bt[highest_priority];
            ct[highest_priority] = time;
            tat[highest_priority] = ct[highest_priority] - at[highest_priority];
            wt[highest_priority] = tat[highest_priority] - bt[highest_priority];

            totalTAT += tat[highest_priority];
            totalWT += wt[highest_priority];

            remaining_burst[highest_priority] = 0;
            count++;
        }
    }

    printf("Solution: \n\n");
    printf("P#\t AT\t BT\t Priority\t CT\t TAT\t WT\t\n\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t\t %d\t %d\t %d\n", i+1, at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time = %f\n", totalTAT / n);
    printf("Average WT = %f\n\n", totalWT / n);
}
