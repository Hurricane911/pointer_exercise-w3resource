#include <stdio.h>

int main()
{
	int m = 29;
	int *ab = &m;
	*ab = 29;
	printf("m addr %p : %d\n", &m, m);
	printf("ab addr %p : %d\n", ab, *ab);

	m = 34;
	printf("m addr %p : %d\n", &m, m);
	printf("ab addr %p : %d\n", ab, *ab);

	*ab = 7;
	printf("m addr %p : %d\n", &m, m);
	printf("ab addr %p : %d\n", ab, *ab);

}