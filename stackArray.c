#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int s[MAX], top = -1;

void push(int data) {
	if (top == MAX - 1)
		printf("Overflow!\n");
	else {
		s[++top] = data;
		printf("Entered in stack Successfully!\n");
	}
}

void pop() {
	if (top == -1) {
		printf("Underflow!\n");
	} else {
		printf("%d Entry removed!\n", s[top--]);
	}
}

void display() {
	if (top == -1) {
		printf("Empty Stack!\n");
	} else {
		printf("Stack: ");
		for (int i = 0; i <= top; i++)
			printf("%d ", s[i]);
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

