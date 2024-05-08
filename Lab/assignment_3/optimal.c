#include <stdio.h>
#include <stdbool.h>

// Function to check if a page exists in memory
bool pageExists(int page, int frames[], int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the optimal page to replace
int findOptimal(int pages[], int pageIndices[], int frames[], int frameSize, int currentIndex, int numPages) {
    int farthest = currentIndex;
    int replaceIndex = -1;
    for (int i = 0; i < frameSize; i++) {
        int j;
        for (j = currentIndex + 1; j < numPages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        // If a page will not be used in the future, return it
        if (j == numPages) {
            return i;
        }
    }
    return (replaceIndex == -1) ? 0 : replaceIndex;
}

int main() {
    int numPages, frameSize, numFaults = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    
    int pages[numPages];
    printf("Enter the page reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);

    int frames[frameSize];
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1; // Initialize all frames to -1 (indicating empty)
    }

    // Simulating page replacement
    for (int i = 0; i < numPages; i++) {
        printf("\nReference to page %d: ", pages[i]);
        if (!pageExists(pages[i], frames, frameSize)) {
            int replaceIndex = findOptimal(pages, pages, frames, frameSize, i, numPages);
            frames[replaceIndex] = pages[i];
            numFaults++;
            printf("Page fault occurred");
        } else {
            printf("No page fault occurred");
        }
        printf("\nCurrent frames: ");
        for (int j = 0; j < frameSize; j++) {
            printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal page faults: %d\n", numFaults);

    return 0;
}