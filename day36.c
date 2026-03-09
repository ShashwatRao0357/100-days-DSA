#include <stdio.h>
#include <string.h>

#define MAX 1000

int arr[MAX];
int size = 0;

void insert(int x) {
    if (size >= MAX) return;
    
    int i;
    for (i = size - 1; (i >= 0 && arr[i] < x); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = x;
    size++;
}

void delete() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", arr[size - 1]);
        size--;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", arr[size - 1]);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char op[10];
    int val;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}