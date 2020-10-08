#include<stdio.h>

void main() {
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter elements\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter element to be searched: ");
	int num, c = 0;
	scanf("%d", &num);
	int min = 0, max = n - 1;
	while (min <= max) {
		int mid = min + (max - min) / 2;
		if (a[mid] == num) {
			++c;
			printf("Element fount at %d\n", (mid + 1));
			break;
		} else if (a[mid] > num)
			max = mid - 1;
		else if (a[mid] < num)
			min = mid + 1;
	}
	if (c == 0)
		printf("Not present in array\n");
}