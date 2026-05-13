#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* count) {
    int i = left, j = mid + 1, k = 0;
    Element* temp = (Element*)malloc((right - left + 1) * sizeof(Element));

    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            count[arr[i].index] += (j - (mid + 1));
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += (j - (mid + 1));
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    free(temp);
}

void mergeSort(Element* arr, int left, int right, int* count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int* count = (int*)calloc(n, sizeof(int));
    Element* arr = (Element*)malloc(n * sizeof(Element));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements to the right: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    free(count);
    free(arr);
    return 0;
}