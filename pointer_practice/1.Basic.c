#include "stdio.h"
int main()
{
	int m = 10; //0x7ffcd41830d4
	int n = 0;
	int o = 0;
	int *z = 0;

	z = &m; //stored m addr:
	// z stores the address of m
	printf("%p\n", &m);
	printf("%p\n", z);
	printf("------------\n");
	// *z stores the value of m = 10 
	printf("dereference z: %d\n", *z);
	// &m is the address of m
	printf("m addr: %p\n", &m);
	// &n stores the address of n
	printf("n addr: %p\n", &n);
	// &o  stores the address of o
	printf("o addr: %p\n", &o);
	// &z stores the address of z
	printf("z addr: %p\n", &z);
}