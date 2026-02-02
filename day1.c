#include <stdio.h>

int main() {
    int n, pos, x;
    printf("Enter number of elements: ");
    if (scanf(" %d", &n) != 1) return 1;

    int arr[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position and value to insert: ");
    scanf("%d", &pos);
    scanf("%d", &x);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}