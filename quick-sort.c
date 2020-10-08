#include<stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void quickSort(int a[], int start, int end) {
	if (start > end)
		return;
	int pivot = start;
	int i = start + 1;
	int j = end;
	while (i <= j) {
		if (a[i] > a[pivot] && a[j] < a[pivot])
			swap(a, i, j);
		if (a[i] <= a[pivot])
			i++;
		if (a[j] >= a[pivot])
			j--;
	}
	swap(a, pivot, j);
	quickSort(a, i, j - 1);
	quickSort(a, i + 1, j);
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int n, i, a[1000];
	printf("Enter size of array\n");
	scanf("%d", &n);
	printf("\nEnter elements of array\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quickSort(a, 0, n - 1);
	printf("\nSorted array is: ");
	printArray(a, n);
	return 0;
}
