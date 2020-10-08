#include<stdio.h>

int main() {
	int n, i, a[100], d, t;
	printf("Enter size of array\n");
	scanf("%d", &n);
	printf("Enter array elements\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i < n; i++) {
		d = i;
		while (d > 0 && a[d] < a[d - 1]) {
			t = a[d - 1];
			a[d - 1] = a[d];
			a[d] = t;
			d--;
		}

	}
	printf("Sorted array in ascending order: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	printf("\n");
	return 0;
}
