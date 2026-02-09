#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    if (scanf("%s", s) == 1) {
        int len = strlen(s);
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}