#include<stdio.h>

void depthFirstTraversal(int graph[5][5], int n, int visited[5]) {

	printf("%d ", n);
	visited[n] = 1;

	for (int i = 0; i < 5; i++) {
		if (graph[n][i] == 1 && visited[i] == 0)
			depthFirstTraversal(graph, i, visited);
	}

}

void dfs(int graph[5][5], int v) {

	int visited[5];

	for (int i = 0; i < 5; i++)
		visited[i] = 0;

	depthFirstTraversal(graph, v, visited);
}

int main() {
	int graph[5][5] = {
		{0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0}
	};
	printf("DFS: ");
	dfs(graph, 0);
}

/* OUTPUT:
DFS: 0 1 2 3 4
*/