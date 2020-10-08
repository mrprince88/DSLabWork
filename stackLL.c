#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *top = NULL, *pointer;

void push(int data) {
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if (top == NULL) {
        top = new;
        pointer = new;
    } else {
        top->next = new;
        top = new;
    }
    printf("Entered Successfully!\n");
}

void pop() {
    if (top == NULL) {
        printf("Underflow!\n");
    } else {
        printf("%d Entry removed!\n", top->data);
        top = top->next;
    }
}

void display() {
    node *temp = malloc(sizeof(node));
    temp = pointer;
    if (top == NULL) {
        printf("Empty Stack!\n");
    } else {
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("Enter 1 to push, 2 to pop, 3 to display and 4 to exit\n");
        int c, n;
        scanf("%d", &c);
        switch (c) {
        case 1:
            printf("Enter entry:");
            scanf("%d", &n);
            push(n);
            break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: printf("Exited Successfully!\n"); exit(0);
        }
    }
}
