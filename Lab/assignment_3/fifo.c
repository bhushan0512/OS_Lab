#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 3 // Maximum number of frames in the memory

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

bool isInMemory(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

int main() {
    int pages[] = {1, 2, 3, 4, 5, 6, 1, 2, 7, 8}; // Reference string
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[MAX_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;

    // Initialize frames with -1 to indicate empty frames
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Page reference string: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\n");

    printf("Page Faults\tFrames\n");
    printf("----------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", pageFaults);

        if (!isInMemory(frames, MAX_FRAMES, pages[i])) {
            frames[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % MAX_FRAMES;
            pageFaults++;
        }

        printFrames(frames, MAX_FRAMES);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}