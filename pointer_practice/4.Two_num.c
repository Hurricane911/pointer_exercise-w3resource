#include <stdio.h>

int main()
{
	int first, second, sum, *ptr, *qtr;

	printf("first num:");
	scanf("%d", &first);
	// printf("%d", first);
	printf("sec num:");
	scanf("%d", &second);

	ptr = &first;
	qtr = &second;

	sum = *ptr + *qtr;
	printf("total: %d", sum);

}