#include <stdio.h>

int main()
{
	int num1, num2, *ptr1, *ptr2;
	printf("num1:");
	scanf("%d", &num1);
	printf("num2:");
	scanf("%d", &num2);

	ptr1 = &num1;
	ptr2 = &num2;

	if(*ptr1 > *ptr2)
		printf("%d", *ptr1);
	else
		printf("%d", *ptr2);
}