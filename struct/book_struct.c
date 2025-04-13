#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_books
{
	int id;
	char title[100];
	char author[100];
	int price;
}t_books;

void find_cheapest(t_books *books, int total_books);

int main(int ac, char **av)
{
	t_books *books;

	FILE *file;
	char file_name[100];
	int total_books;
	int i = 0;

	if(ac != 2)
	{
		printf("./a.out <books.txt> format:%s", av[0]);
		scanf("%s", file_name);
		// printf("%s", file_name);
	}
	else
	{
		strcpy(file_name, av[1]);
	}

	file = fopen(file_name, "r");
	if(!file)
	{
		printf("file error");
		return (1);
	}

	fscanf(file, "%d", &total_books);

	
	books = malloc(sizeof(t_books) * total_books);
	if(!books)
	{
		printf("malloc error");
		return (1);
	}

	while(i < total_books && !feof(file))
	{
		books[i].id = i+1;
		fscanf(file, "%s %s %d", books[i].title, books[i].author, &books[i].price);
		i++;
	}
	i = 0;
	int search_id = 0;

	while(i < total_books)
	{
		// if(search_id == books[i].id)
		printf("-----books id %d---------\n", books[i].id);
		printf("title: %s\n", books[i].title);
		printf("author: %s\n", books[i].author);
		printf("title: %d\n", books[i].price);
		i++;
	}
	
	// find cheapest
	find_cheapest(books, total_books);

}

void find_cheapest(t_books *books, int total_books)
{
	int cheapest_index = 0;
	int expensive_index = 0;
	int i = 0;

	while(i < total_books)
	{
		if(books[i].price < books[cheapest_index].price)
			cheapest_index = i;
		if (books[i].price > books[expensive_index].price)
			expensive_index = i;
		i++;
	}

	printf("\n----- Cheapest Book -----\n");
    printf("Title: %s\n", books[cheapest_index].title);
    printf("Author: %s\n", books[cheapest_index].author);
    printf("Price: %d\n", books[cheapest_index].price);
    
    // Print most expensive book details
    printf("\n----- Most Expensive Book -----\n");
    printf("Title: %s\n", books[expensive_index].title);
    printf("Author: %s\n", books[expensive_index].author);
    printf("Price: %d\n", books[expensive_index].price);
}

