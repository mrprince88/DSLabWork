#include<stdio.h>
#include<stdlib.h>

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
}

int dequeue() {
	if (front == NULL)
		return -2147483648;
	else {
		int entry = front->data;
		node *temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		free(temp);
		return entry;
	}
}

void breadthFirstTraversal(int graph[5][5], int n, int visited[5]) {

	int size = 0;

	enqueue(n);
	size++;

	while (size > 0) {

		int curr = dequeue();
		size--;

		if (visited[curr] == 0) {

			printf("%d ", curr);

			visited[curr] = 1;

			for (int i = 0; i < 5; i++)
				if (graph[curr][i] == 1) {
					enqueue(i);
					size++;
				}
		}
	}

}

void bfs(int graph[5][5], int n) {

	int visited[5];

	for (int i = 0; i < 5; i++)
		visited[i] = 0;

	breadthFirstTraversal(graph, n, visited);
}

int main() {
	int graph[5][5] = {
		{0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0}
	};
	printf("BFS: ");
	bfs(graph, 0);
}

/* OUTPUT:
BFS: 0 1 2 3 4
*/