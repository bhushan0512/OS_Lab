#include <stdio.h>

int findLRUIndex(int counter[], int no) {
    int i, min = counter[0], idx = 0;
    for (i = 1; i < no; i++) {
        if (counter[i] < min) {
            min = counter[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int i, j, n, a[50], frame[10], no, k, count = 0, counter[10];

    printf("ENTER THE NUMBER OF PAGES:");
    scanf("%d", &n);

    printf("\nENTER THE PAGE NUMBER:");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    printf("\nENTER THE NUMBER OF FRAMES:");
    scanf("%d", &no);

    for (i = 0; i < no; i++) {
        frame[i] = -1;
        counter[i] = 0;
    }

    printf("Ref strings\t Page frames\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t", a[i]);
        int avail = 0;

        for (k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                counter[k] = i;
                break;
            }
        }

        if (avail == 0) {
            int lruIndex = findLRUIndex(counter, no);
            frame[lruIndex] = a[i];
            counter[lruIndex] = i;
            count++;
        }

        for (k = 0; k < no; k++)
            printf("%d\t", frame[k]);
        printf("\n");
    }
    printf("\nPage Fault Is %d\n", count);
    return 0;
}
