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
	for (int i = 0; i < n; i++)
		if (a[i] == num) {
			++c;
			printf("\nElement found at %d\n", (i + 1));
			break;
		}
	if (c == 0)
		printf("\nNot present in array");
}