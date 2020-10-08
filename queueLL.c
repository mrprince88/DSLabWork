#include<stdio.h>
#include<stdlib.h>
#define max 100

struct node {
	int data;
	struct node *next;
};

typedef struct node node;
node *front = NULL, *rear = NULL, *temp;

void enqueue(int data) {
	node *new = malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	if (rear == NULL) {
		front = new;
		rear = new;
	} else {
		rear->next = new;
		rear = new;
	}
	printf("Element inserted successfully\n");
}

void dequeue() {
	if (front == NULL)
		printf("Empty Queue\n");
	else {
		int entry = front->data;
		front = front->next;
		printf("%d entry deleted\n", entry);
	}
}

void display() {
	temp = front;
	if (front == NULL)
		printf("Empty Queue");
	else {
		printf("Queue: ");
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
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


