#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;  // hash table size

// Initialize hash table
void init() {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == -1)
            return 0;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    init();

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}