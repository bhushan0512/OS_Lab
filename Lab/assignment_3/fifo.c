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
    int frameIndex = 0;

    for (int i = 0; i < maxFrames; i++) {
        memory[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Page: %d, Memory: ", pages[i]);
        if (!isInMemory(pages[i], memory, maxFrames)) {
            faults++;
            memory[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % maxFrames;
        }
        displayMemory(memory, maxFrames);
    }

    printf("Total Page Faults: %d\n", faults);

    return 0;
}