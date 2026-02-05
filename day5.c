#include <stdio.h>

int main() {
    int p, q;

    printf("Enter the number of entries for Server Log 1: ");
    if (scanf("%d", &p) != 1) return 0;

    int log1[p];
    printf("Enter %d sorted arrival times for Log 1: ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("\nEnter the number of entries for Server Log 2: ");
    if (scanf("%d", &q) != 1) return 0;

    int log2[q];
    printf("Enter %d sorted arrival times for Log 2: ", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    printf("\n--- Final Chronological Log ---\n");

    int i = 0; 
    int j = 0; 

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    printf("\n\nProcessing complete.\n");
    return 0;
}