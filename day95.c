#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int* start, int startSize, int* end, int endSize) {
    if (startSize == 0) return 0;

    // 1. Sort both arrays
    qsort(start, startSize, sizeof(int), compare);
    qsort(end, endSize, sizeof(int), compare);

    int rooms_needed = 0;
    int end_ptr = 0;

    for (int start_ptr = 0; start_ptr < startSize; start_ptr++) {
        if (start[start_ptr] < end[end_ptr]) {
            rooms_needed++;
        } else {
            end_ptr++;
        }
    }

    return rooms_needed;
}

int main() {
    int start[] = {2, 9, 6};
    int end[] = {4, 12, 10};
    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(start, n, end, n));
    
    return 0;
}