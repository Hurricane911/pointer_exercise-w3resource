#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{

    int num; 
    struct s_node *next;
    
}t_node;

t_node *create_node(int data)
{
    t_node *new_node = malloc(sizeof(t_node));
    if(!new_node)
        return NULL;
    new_node->num = data;
    new_node->next = NULL;
    return new_node;

}

int main()
{
    t_node *head = NULL;   
    t_node *current = NULL;
    int num = 0;
    int data;
    int i = 0;
    printf("num_nodes:");
    scanf("%d", &num);

    while(i < num)
    {
        printf("data of nodes %d = ", i + 1);
        scanf("%d", &data);
        t_node *new_node = create_node(data);
        if(!new_node)
        {
            printf("malloc failed");
            return 1;
        }
        if (head == NULL)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        i++;
    }

    current = head;
    while (current != NULL)
    {
        printf("data of nodes = %d\n", current->num);
        current = current->next;
    }

    current = head;
    while (current != head)
    {
        t_node *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;

}
