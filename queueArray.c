#include<stdio.h>
#include<stdlib.h>
#define max 100
int q[max], front = -1, rear = -1;

void enqueue(int data) {
	if (rear == max - 1) {
		printf("Overflow\n");
		return;
	}
	if (front == -1)
		front = 0;
	q[++rear] = data;
	printf("Entered Successfully at %d\n", rear);
}

void dequeue() {
	if (rear == -1 || front > rear) {
		printf("Empty Queue\n");
		return;
	}
	printf("%d entry deleted\n", q[front++]);
}

void display() {
	if (rear == -1 || front > rear) {
		printf("EmptyQueue\n");
		return;
	}
	printf("Queue: ");
	for (int i = front; i <= rear; i++)
		printf("%d ", q[i]);
	printf("\n");
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