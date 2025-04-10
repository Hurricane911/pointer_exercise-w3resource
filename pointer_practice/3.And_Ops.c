#include <stdio.h>

int main()
{
	int z = 0;
	int m = 300;                                                                                                    
	double fx = 300.600006;                                                                                         
	int *cht = &z;

	printf("using & operator:\n");
	printf("------------------\n");
	printf("m addr: %p\n", &m);
	printf("fx addr: %p\n", &fx);
	printf("cht addr: %p\n", cht);
	printf("z addr: %p\n", &z);
	printf("\n\n");
	printf("Using & and * operator:\n");
	printf("------------------\n");
	printf("m: %d\n", m);
	printf("fx: %f\n", fx);
	printf("cht: %d\n", *cht);
	printf("z: %d\n", z);

}