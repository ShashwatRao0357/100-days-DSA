#include <stdio.h>

int main() {
    static int a, b;
    static long long result = 1;
    static int initialized = 0;

    if (!initialized) {
        if (scanf("%d %d", &a, &b) != 2) return 0;
        initialized = 1;
    }

    if (b > 0) {
        result *= a;
        b--;
        main();
    } else {
        printf("%lld\n", result);
    }

    return 0;
}