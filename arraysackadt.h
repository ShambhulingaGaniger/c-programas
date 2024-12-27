#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct array_stack
{
    void** st;
    int size, top, count;
} AST;
AST* create_stack()
{
    AST* head;
    head = (AST*)malloc(sizeof(AST));
    if (head)
    {
        printf("Enter the size of stack\n");
        scanf("%d", &head->size);
        head->st = (void**)calloc(head->size, sizeof(void*));
        if (head->st)
        {
            head->top = -1;
            head->count = 0;
            return head;
        }
        else
        {
            free(head);
            return NULL;
        }
    }
    return NULL;
}
bool stack_full(AST* head)
{ 
    return head->top == head->size - 1;
}
bool push_stack(AST *head, void *dpin)
{
    if (stack_full(head))  
        return false;

    head->top++;
    head->st[head->top] = dpin;
    head->count++;
    return true;
}
bool empty_stack(AST* head)
{
    return head->top == -1;
}
void* pop_stack(AST* head)
{
    void* dpout;
    if (empty_stack(head))
        return NULL;

    dpout = head->st[head->top];
    head->top--;
    head->count--;
    return dpout;
}
void* stack_top(AST* head)
{
	
    if (empty_stack(head))
        return NULL;

    return head->st[head->top];
}
int stack_count(AST* head)
{
    return head->count;
}
void display_stack(AST* head, void (*dp)(void*))
{
    int i;
    if (empty_stack(head))
    {
        printf("Stack is empty\n");
    }
    for (i = head->top; i >= 0; i--)
        dp(head->st[i]);
}
bool destroy_stack(AST* head)
{
    if (head)
    {
        while (head->count != 0)
        {
             free(head->st[head->top]);
            head->top--;
            head->count--;
        }
        free(head->st);
        free(head);
        return true;
    }
    return false;
}

