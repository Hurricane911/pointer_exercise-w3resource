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

int main(int argc, char **argv)
{
    t_student *students;
    int total_students;
    int i = 0;
    FILE *file;
    char filename[100];
    
    //./a.out, no txt
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        printf("Enter the filename: ");
        scanf("%s", filename);
    }
    else
    {
        // with txt
        strcpy(filename, argv[1]);
    }
    
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    
    // Read the number of students from the first line
    fscanf(file, "%d", &total_students);
    
    students = malloc(sizeof(t_student) * total_students);
    if (students == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }
    
    // Read student data from file
    while (i < total_students && !feof(file))
    {
        students[i].id = i + 1;
        fscanf(file, "%s %d", students[i].name, &students[i].age);
        i++;
    }
    
    fclose(file);
    
    // Display all students
    i = 0;
    printf("\n=== Student Records ===\n");
    while (i < total_students)
    {
        printf("--------\n");
        printf("Student ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        i++;
    }
    
    // Search functionality
    int search_id;
    int found = 0;
    
    printf("\nEnter student ID to search: ");
    scanf("%d", &search_id);
    
    i = 0;
    while (i < total_students)
    {
        if (search_id == students[i].id)
        {
            printf("\n=== Search Result ===\n");
            printf("Student ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            found = 1;
            break;
        }
        i++;
    }
    
    if (!found)
    {
        printf("Student with ID %d not found!\n", search_id);
    }
    
    free(students);
    return 0;
}