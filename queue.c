#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *next;
    };

struct node *create_node(int value)
{
    struct node *a = malloc(sizeof(struct node));
    if (a == NULL)
    {
        return NULL;
    }

    a->data = value;
    a->next = NULL;

    return a;
}

int enqueue(struct node **first, int value)
{
    struct node *current;
    struct node *new_node;
    
    new_node = create_node(value);
    if (new_node == NULL)
    {
        return 1;
    }
    
    if (*first == NULL)
    {
        *first = new_node;
        return 0;
    }

    current = *first;
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

    return 0;
}

int dequeue(struct node **first)
{
    struct node *current_first;
    
    if (first == NULL || *first == NULL)
    {
        printf("The queue is empty.....");
        return 1;
    }

    current_first = *first;
    *first = current_first->next;
    free(current_first);

    return 0;
    
}