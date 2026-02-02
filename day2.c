#include <stdio.h>

int main() {
    int n, pos;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Updated array: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d%s", arr[i], (i == n - 2) ? "" : " ");
    }
    printf("\n");

    return 0;
}