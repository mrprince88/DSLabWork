#include<stdio.h>

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main() {
	int n, a[100], i;
	printf("Enter size of array\n");
	scanf("%d", &n);
	printf("\nEnter elements of array\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergeSort(a, 0, n - 1);
	printf("\nSorted array is \n");
	printArray(a, n);
	return 0;
}


/*OUTPUT
Enter size of array
4

Enter elements of array
5
3
1
2

Sorted array is
1 2 3 5
*/
