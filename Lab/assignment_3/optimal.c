#include <stdio.h>
#include <stdbool.h>

bool isInMemory(int page, int memory[], int n) {
    for (int i = 0; i < n; i++) {
        if (memory[i] == page) {
            return true;
        }
    }
    return false;
}

void displayMemory(int memory[], int n) {
    for (int i = 0; i < n; i++) {
        memory[i]!=-1?printf("%d ", memory[i]):printf("_ ");
    }
    printf("\n");
}

int findOptimal(int pages[], int memory[], int n, int maxFrames, int start) {
    int index = -1, farthest = start;
    for (int i = 0; i < maxFrames; i++) {
        int j;
        for (j = start; j < n; j++) {
            if (memory[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return (index == -1) ? 0 : index;
}

int main() {
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int maxFrames;
    printf("Enter number of frames: ");
    scanf("%d", &maxFrames);

    int memory[maxFrames];
    int faults = 0;

    for (int i = 0; i < maxFrames; i++) {
        memory[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Page: %d, Memory: ", pages[i]);
        if (!isInMemory(pages[i], memory, maxFrames)) {
            faults++;
            int pos = findOptimal(pages, memory, n, maxFrames, i + 1);
            memory[pos] = pages[i];
        }
        displayMemory(memory, maxFrames);
    }

    printf("Total Page Faults: %d\n", faults);

    return 0;
}