#include <stdio.h>

int main()
{
    int n, m, i, j, k, alloc[50][30], max[50][30], avail[30];
    
    // Getting process and resource count
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    
    // Getting values for allocation for all the processes
    printf("Enter the values for allocation:\n");
    for (i = 0; i < n; i++)
    {
        printf("Allocation values for P[%d]:", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Getting values for max for all the processes
    printf("Enter the values for max:\n");
    for (i = 0; i < n; i++)
    {
        printf("Max values for P[%d]:", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Getting values for available
    printf("Enter the values for available:\n");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;

                // Checking if the process can be allocated
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    // Process can be allocated
                    ans[ind++] = i;

                    // Updating available resources
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    //To check if the System is safe or not
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");

        // Printing the safe sequence
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d\n", ans[n - 1]);
    }
}
