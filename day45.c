#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node** createQueue(int* front, int* rear) {
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 500);
    *front = *rear = 0;
    return queue;
}

void enQueue(struct Node** queue, int* rear, struct Node* new_node) {
    queue[*rear] = new_node;
    (*rear)++;
}

struct Node* deQueue(struct Node** queue, int* front) {
    (*front)++;
    return queue[*front - 1];
}

void printLevelOrder(struct Node* root) {
    int front, rear;
    struct Node** queue = createQueue(&front, &rear);
    struct Node* temp_node = root;

    while (temp_node) {
        printf("%d ", temp_node->data);

        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        temp_node = deQueue(queue, &front);
    }
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    printLevelOrder(root);

    return 0;
} 