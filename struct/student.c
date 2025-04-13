#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_student
{
    int id;
    char name[50];
    int age;
    float total_marks;
} t_student;

int main(int ac, char **av)
{
    t_student *students;
    int total_student;

    FILE *file;
    char filename[100];
    int i = 0;

    if (ac != 2)
    {
        printf("<file_name> format: %s\n", av[0]);
        scanf("%s", filename);
        // printf("%s", filename);
    }
    else
    {
        strcpy(filename, av[1]);
        // printf("%s", filename);
    }

    file = fopen(filename, "r");
    if(!file)
    {
        printf("error files");
        return 1;
    }

    fscanf(file, "%d", &total_student);
    
    students = malloc(sizeof(t_student) * total_student);
    if(!students)
    {
        printf("malloc erro");
        fclose(file);
        return (1);
    }
    
    while(i < total_student && !feof(file))
    {
        students[i].id = i + 1;
        fscanf(file, "%s %d", students[i].name, &students[i].age);
        i++;
    }
    // printf("%s", students[0].name);

    int search_id;
    int found = 0;
    i = 0;
    printf("which id to search: ");
    scanf("%d", &search_id);

    while(i < total_student)
    {
        if(search_id == students[i].id)
        {
            printf("%d\n", students[i].id);
            printf("%s\n", students[i].name);
            printf("%d\n", students[i].age);
            found = 1;
            break;
        }
        i++;
    }
    if(!found)
    {
        printf("students id not found");
    }
    free(students);
    return 0;
    
}