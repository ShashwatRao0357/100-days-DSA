#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of integers (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int j = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;             
            arr[j] = arr[i]; 
        }
    }

    printf("Unique elements: ");
    for (int i = 0; i <= j; i++) {
        printf("%d", arr[i]);
        if (i < j) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}