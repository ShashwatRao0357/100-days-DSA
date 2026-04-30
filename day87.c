#include <stdio.h>
#include <stdbool.h>

bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + arr[i] <= mid) {
            currentSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            currentSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; 

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int low = maxVal;
    int high = sum;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;   
            high = mid - 1;
        } else {
            low = mid + 1;  
        }
    }
    return result;
}

int main() {
    int n, m;
    
    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = allocateBooks(arr, n, m);
    printf("%d\n", answer);

    return 0;
}