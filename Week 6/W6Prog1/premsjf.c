#include<stdio.h>

struct Process
{
int processID;
int burstTime;
int arrivalTime;
int waitingTime;
int turnaroundTime;
};

void calculateTimes(struct Process processes[], int n)
{
int remainingTime[n], completed = 0, currentTime = 0, shortest, finishTime, minBurstTime;

for (int i = 0; i < n; i++)
remainingTime[i] = processes[i].burstTime;

while (completed != n)
{
shortest = -1;
minBurstTime = 9999;

for (int j = 0; j < n; j++)
{
if (processes[j].arrivalTime <= currentTime && remainingTime[j] < minBurstTime && remainingTime[j] > 0)
{
shortest = j;
minBurstTime = remainingTime[j];
}
}

if (shortest == -1)
{
currentTime++;
continue;
}

remainingTime[shortest]--;
minBurstTime = remainingTime[shortest];

if (minBurstTime == 0)
{
completed++;
finishTime = currentTime + 1;
processes[shortest].waitingTime = finishTime - processes[shortest].burstTime - processes[shortest].arrivalTime;
processes[shortest].waitingTime = (processes[shortest].waitingTime < 0) ? 0 : processes[shortest].waitingTime;
}
currentTime++;
}

for (int i = 0; i < n; i++)
processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
}

void displayProcessDetails(struct Process processes[], int n)
{
printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

for (int i = 0; i < n; i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime,
processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnaroundTime);
}
}

void calculateAverageTimes(struct Process processes[], int n)
{
int totalWaitingTime = 0, totalTurnaroundTime = 0;

for (int i = 0; i < n; i++)
{
totalWaitingTime += processes[i].waitingTime;
totalTurnaroundTime += processes[i].turnaroundTime;
}

float averageWaitingTime = (float)totalWaitingTime / n;
float averageTurnaroundTime = (float)totalTurnaroundTime / n;

printf("Average Waiting Time: %.2f\n", averageWaitingTime);
printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main()
{
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);

struct Process processes[n];
printf("Enter the burst time and arrival time for each process:\n");

for (int i = 0; i < n; i++)
{
processes[i].processID = i + 1;
printf("Process %d\n", processes[i].processID);
printf("Burst Time: ");
scanf("%d", &processes[i].burstTime);
printf("Arrival Time: ");
scanf("%d", &processes[i].arrivalTime);
}

calculateTimes(processes, n);
displayProcessDetails(processes, n);
calculateAverageTimes(processes, n);

return 0;
}
