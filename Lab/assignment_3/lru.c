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
        printf("%d ", memory[i]);
    }
    printf("\n");
}

void updateLRU(int memory[], int n, int index) {
    int temp = memory[index];
    for (int i = index; i < n - 1; i++) {
        memory[i] = memory[i + 1];
    }
    memory[n - 1] = temp;
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
            updateLRU(memory, maxFrames, 0);
            memory[maxFrames - 1] = pages[i];
        } else {
            int index;
            for (index = 0; index < maxFrames; index++) {
                if (memory[index] == pages[i]) {
                    break;
                }
            }
            updateLRU(memory, maxFrames, index);
        }
        displayMemory(memory, maxFrames);
    }

    printf("Total Page Faults: %d\n", faults);

    return 0;
}