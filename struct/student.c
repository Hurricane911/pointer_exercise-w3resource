#include <stdio.h>
#include <stdlib.h>

typedef struct s_student
{
    int id;
    char name[50];
    int age;
    float total_marks;
}t_student;

int main(int ac, char **av)
{
    t_student *students;

    int total_students;
    int i = 0;

    printf("Enter the number of students: ");
    scanf("%d", &total_students);

    students = malloc(sizeof(t_student)  * total_students);
    if (students == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    while(i < total_students)
    {
        students[i].id = i + 1;
        printf("student id: %d \n", students[i].id);
    
        printf("name: ");
        scanf("%s", students[i].name);
        printf("age: ");
        scanf("%d", &students[i].age);
        i++;
    }

    i = 0;
    while(i < total_students)
    {  
        printf("--------");
        printf("student id: %d \n", students[i].id);
        printf("name: %s\n",students[i].name );
        printf("age: %d\n", students[i].age);
        i++;
    }

    int j = 0;
    printf("enter id for search:");
    scanf("%d", &j);

    int x = 0;
    while(x < total_students)
    {
        if(students[x].id == j)
        {
            printf("student id: %d \n", students[x].id);
            printf("name: %s\n",students[x].name );
            printf("age: %d\n", students[x].age);
            break;
        }
        x++;
    }

}