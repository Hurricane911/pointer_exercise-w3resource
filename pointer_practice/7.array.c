#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i = 0;
	if(ac >= 5)
	{
		while(i < ac-1)
		{
			printf("%d: %d\n", i, atoi(av[i+1]));
			i++;
		}
	}
	else
		printf("need 5 nums");
}