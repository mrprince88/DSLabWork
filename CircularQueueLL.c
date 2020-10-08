#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data) {
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->next = NULL;
	if ((rear == NULL) && (front == NULL)) {
		front = rear = n;
		rear->next = front;
	} else {
		rear->next = n;
		rear = n;
		n->next = front;
	}
}

void dequeue() {
	struct node* t;
	t = front;
	if ((front == NULL) && (rear == NULL))
		printf("Queue is Empty\n");
	else if (front == rear) {
		front = rear = NULL;
		printf("%d deleted\n", t->data);
		free(t);
	} else {
		front = front->next;
		rear->next = front;
		printf("%d deleted\n", t->data);
		free(t);
	}
}

void display() {
	struct node* t;
	t = front;
	if ((front == NULL) && (rear == NULL))
		printf("\nQueue is Empty");
	else {
		printf("Queue: ");
		do {
			printf("%d ", t->data);
			t = t->next;
		} while (t != front);
		printf("\n");
	}
}

int main() {
	while (1) {
		printf("Enter 1 to enqueue, 2 to dequeue, 3 to display and 4 to exit\n");
		int c, n;
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("Enter entry:");
			scanf("%d", &n);
			enqueue(n);
			break;
		case 2: dequeue(); break;
		case 3: display(); break;
		case 4: printf("Exited Successfully\n"); exit(0);
		}
	}
}


