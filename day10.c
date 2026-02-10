#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j, isPalindrome = 1;

    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}