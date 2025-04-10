#include <stdio.h>

long addnums(long *n1, long *n2)
{
	long sum = (*n1 + *n2);
	return sum;
}

int main()
{
	long first, second, sum, *ptr, *qtr;

	printf("1:");
	scanf("%ld", &first);
	printf("2:");
	scanf("%ld", &second);
	
	sum = addnums(&first, &second);

	printf("total: %ld", sum);
	
}