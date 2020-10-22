#include<stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void Heapify(int a[], int n, int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < n && a[leftChild] > a[largest])
		largest = leftChild;
	if (rightChild < n && a[rightChild] > a[largest])
		largest = rightChild;
	if (largest != i) {
		swap(a, i, largest);
		Heapify(a, n, largest);
	}
}

void heapSort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
	for (int i = n - 1; i >= 1; i--) {
		swap(a, i, 0);
		Heapify(a, i, 0);
	}
}

void printArray(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int n, a[100], i;
	printf("Enter size of array\n");
	scanf("%d", &n);
	printf("\nEnter elements of array\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	heapSort(a, n);
	printf("\nSorted array is: ");
	printArray(a, n);
	return 0;
}