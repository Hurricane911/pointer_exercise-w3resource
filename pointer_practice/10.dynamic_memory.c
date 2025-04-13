#include <stdio.h>
#include <stdlib.h>

void sorting(int *sort_nums, int total_nums);

int main (int ac, char **av)
{
	int i = 0;
	int *sort_nums = 0;
	int total_nums = 0;

	while(av[i+1])
		i++;
	printf("%d\n", i);
	total_nums = i;
	sort_nums = malloc(sizeof(int) * total_nums);
	if(!sort_nums)
	{
		printf("malloc_error");
		free(sort_nums);
		return 1;
	}
	i = 0;
	while(i < total_nums)
	{
		sort_nums[i] = atoi(av[i+1]);
		printf("%d\n", sort_nums[i]);
		i++;
	}

	sorting(sort_nums, total_nums);
	free(sort_nums);
	return (0);
}

void sorting(int *sort_nums, int total_nums)
{
	int temp = 0;
	int i =0; 
	while(i < total_nums)
	{
		if(sort_nums[i] > temp)
			temp = sort_nums[i];
		i++;
	}
	printf("largest: %d", temp);
}