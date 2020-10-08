#include<stdio.h>
#include<stdlib.h>

int array[10], front = -1, rear = -1, size = 10;

int enqueue(int data) {
	if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
		printf("Queue is full\n");
	} else if (front == -1) {
		rear++;
		front++;
	} else if (rear == size - 1 && front > 0) {
		rear = 0;
	} else {
		rear++;
	}
	array[rear] = data;
}

void display() {
	int i;
	printf("Queue: ");
	if (front > rear) {
		for (i = front; i < size; i++) {
			printf("%d ", array[i]);
		}
		for (i = 0; i <= rear; i++)
			printf("%d ", array[i]);
	} else {
		for (i = front; i <= rear; i++)
			printf("%d ", array[i]);
	}
	printf("\n");
}

void dequeue() {
	if (front == -1) {
		printf("Queue is empty\n");
	} else if (front == rear) {
		printf("%d deleted\n", array[front]);
		front = -1;
		rear = -1;
	} else {
		printf("%d deleted\n", array[front]);
		front++;
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