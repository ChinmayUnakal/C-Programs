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

int append(struct node *head, int value)
{
    struct node *current;
    struct node *new_node;

    if (head == NULL)
    {
        return 1;
    }

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    new_node = create_node(value);
    if (new_node == NULL)
    {
        printf("Allocation failed!");
        return 1;
    }

    current->next = new_node;

    return 0;
}

int insert_front(struct node **head, int value)
{
    struct node *first;
    struct node *old;

    old = *head;
    first = create_node(value);
    if (first == NULL)
    {
        printf("Allocation failed!");
        return 1;
    }

    *head = first;
    first->next = old;

    return 0;
}

int insert_back(struct node *head, int value)
{
    struct node *current;
    struct node *new_node;

    if (head == NULL)
    {
        return 1;
    }
    
    new_node = create_node(value);
    if (new_node == NULL)
    {
        return 1;
    }

    current = head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

    return 0;
}

int delete_front(struct node **head)
{
    struct node *current_first;

    if (head == NULL || *head == NULL)
    {
        return 1;
    }

    current_first = *head;
    *head = current_first->next;
    free(current_first);

    return 0;
    
}

int delete_value(struct node **head, int value)
{
    struct node *current;
    struct node *prev;

    if (head == NULL || *head == NULL)
    {
        return 1;
    }

    current = *head;

    if (current->data == value)
    {
       return delete_front(head);
    }

    while (current != NULL && current->data != value)
    {
            prev = current;
            current = current->next;
    }
    if (current != NULL)
        {   
            prev->next = current->next;
            free(current);
            return 0;
        }
    
    return 1;
}

int delete_back(struct node **head)
{
    struct node *current;
    struct node *last;
    
    if (head == NULL || *head == NULL)
    {
        return 1;
    }

    current = *head;

    if (current->next == NULL)
    {
        printf("There is only one node in this linked list.");

        free(*head);
        *head = NULL;

        return 0;
    }

    while (current->next->next != NULL)
    {
        current = current->next;
    }
    
    last = current->next;
    free(last);
    current->next = NULL;

    return 0;
}

struct node *search(struct node *head, int value)
{
    struct node *current;
    current = head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }

        current = current->next;
    }
    return NULL;
}

void reverse_list(struct node **head)
{
    struct node *previous;
    struct node *current;
    struct node *next;

    if (head == NULL || *head == NULL)
    {
        return;
    }
    previous = NULL;
    current = *head;

    while (current != NULL)        
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;  
    }
    *head = previous;
}

size_t list_length(struct node *head)
{
    struct node *current;
    size_t count = 0;

    if (head == NULL)
    {
        return 0;
    }

    current = head;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    return count;
}

void free_list(struct node *head)
{
    struct node *newp;
    struct node *current;

    current = head;

    while ( current != NULL )
    {
        newp = current->next;
        free(current);
        current = newp;
    }
}

int main()
{

    struct node *head;
    struct node *current;
    
    head = create_node(100);
    if (head == NULL)
    {
        printf("Allocation Failed!");
        return 1;
    }

    append(head, 200);
    append(head, 300);
    append(head, 400);
    append(head, 500);
    
    current = head;
    while (current != NULL)
    {
        printf("Before modification of data = %d\n", current->data);
        current = current->next;
    }

    insert_front(&head, 50);
    current = head;
    while (current != NULL)
    {
        printf("After insertion of new head data = %d\n", current->data);
        current = current->next;
    }

    delete_front(&head);

    current = head;
    while (current != NULL)
    {
        printf("After deletion of head data = %d\n", current->data);
        current = current->next;
    }

    delete_back(&head);
    current = head;
    while (current != NULL)
    {
        printf("After deletion of back data = %d\n", current->data);
        current = current->next;
    }

    insert_back(head, 500);
    current = head;
    while (current != NULL)
    {
        printf("After insertion of back data = %d\n", current->data);
        current = current->next;
    }

    current = search(head, 300);
    if (current != NULL)
    {
        printf("The result of the search is: %d\n", current->data);
    }
    else
    {
        printf("Value not found\n");
    }

    delete_value(&head, 300);
    current = head;
    while (current != NULL)
    {
        printf("After deletion of value = %d\n", current->data);
        current = current->next;
    }    

    reverse_list(&head);
    current = head;
    while (current != NULL)
    {
        printf("After reversing values = %d\n", current->data);
        current = current->next;
    }

    printf("The list's length is %zu", list_length(head));

    free_list(head);
}