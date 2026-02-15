#include <stdio.h>

int main() {
    int n, i, j;
    int isIdentity = 1;

    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
    }

    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}