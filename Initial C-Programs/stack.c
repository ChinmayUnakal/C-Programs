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

int push(struct node **top, int value)
{
    struct node *first;
    struct node *old;

    old = *top;
    first = create_node(value);
    if (first == NULL)
    {
        printf("Allocation failed!");
        return 1;
    }

    *top = first;
    first->next = old;

    return 0;
}

int pop(struct node **top, int *value)
{
    struct node *current_first;

    if (top == NULL || *top == NULL)
    {
        return 1;
    }

    current_first = *top;
    *top = current_first->next;
    *value = current_first->data;
    free(current_first);

    return 0;
}

int peek(struct node *top, int *value)
{
    if ( top == NULL )
    {
        return 1;
    }

    *value = top->data;

    return 0;
}

int is_empty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int free_stack(struct node **top)
{
    struct node *old;
    
    old = *top;
    while(old != NULL)
    {
       *top = old->next;
       free(old);
       old = *top;
    }
    
    return 0;
}

int main()
{   
    struct node *top = NULL;
    struct node *current;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);

    current = top;
    while(current != NULL)
    {
       printf("Before push : %d\n", current->data);
       current = current->next;
    }

    push(&top, 60); 
    current = top;
    while(current != NULL)
    {
       printf("After push : %d\n", current->data);
       current = current->next;
    }
    
    int value;
    if(pop(&top, &value) == 0)
    {
       printf("Popped : %d\n", value);

    current = top;
       while(current != NULL)
       {
           printf("After pop : %d\n", current->data);
           current = current->next;
       }
    }
    else{
        printf("Stack is Empty.....");
    }
    
   int valueP;
   if (peek(top, &valueP) == 0)
   {
       printf("Peeked at : %d\n", valueP);
   }

   if (is_empty(top))
   {
       printf("Stack is empty\n");
   }
   else{
       printf("Stack ain't empty\n");
   }

   if(free_stack(&top) == 0)
   {
      printf("Stack freed.....\n");
   }


}