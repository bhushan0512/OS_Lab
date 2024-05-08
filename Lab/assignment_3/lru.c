#include<stdio.h>
#include<stdlib.h>

#define MAX_PAGES 100

int main() {
    int pages[MAX_PAGES], page_frames, num_pages, page_faults = 0;
    
    printf("Enter number of page frames: ");
    scanf("%d", &page_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);
    
    printf("Enter the reference string: ");
    for(int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }
    
    int page_table[page_frames];
    int page_table_time[page_frames];
    for(int i = 0; i < page_frames; i++) {
        page_table[i] = -1;
        page_table_time[i] = 0;
    }
    
    for(int i = 0; i < num_pages; i++) {
        int page_found = 0;
        for(int j = 0; j < page_frames; j++) {
            if(page_table[j] == pages[i]) {
                page_found = 1;
                page_table_time[j] = i + 1;
                break;
            }
        }
        
        if(!page_found) {
            int lru = 0;
            for(int j = 1; j < page_frames; j++) {
                if(page_table_time[j] < page_table_time[lru]) {
                    lru = j;
                }
            }
            
            page_table[lru] = pages[i];
            page_table_time[lru] = i + 1;
            page_faults++;
        }
    }
    
    printf("Number of page faults: %d\n", page_faults);
    
    return 0;
}