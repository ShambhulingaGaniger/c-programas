#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
    void *dp;
    struct NODE *next;
} node;

typedef struct STACK {
    node *top;
    int count;
} stack;

stack *createstack() {
    stack *head;
    head = (stack *)malloc(sizeof(stack));
    if (head) {
        head->top = NULL;
        head->count = 0;
        return head;
    }
    return NULL;
}

bool pushstack(stack *head, void *dp) {
    node *pin;
    pin = (node *)malloc(sizeof(node));
    if (pin) {
        pin->next = head->top;
        pin->dp = dp;
        head->top = pin;
        head->count++;
        return true;
    }
    return false;
}

void *popstack(stack *head) {
    void *dp;
    node *pout;
    if (head->top != NULL) {
        pout = head->top;
        head->top = pout->next;
        dp = pout->dp;
        head->count--;
        free(pout);
        return dp;
    }
    return NULL;
}

void *stacktop(stack *head) {
    if (head->top != NULL) {
        return head->top->dp;
    }
    return NULL;
}

bool stackempty(stack *head) {
    return (head->top == NULL);
}

bool stackfull() {
    node *p;
    p = (node *)malloc(sizeof(node));
    if (p) {
        free(p);
        return false;
    }
    return true;
}

void *stackdisplay(stack *head, void (*pd)(void *)) {
    node *temp;
    for (temp = head->top; temp != NULL; temp = temp->next) {
        pd(temp->dp);
    }
    return NULL;
}

void stackdestroy(stack *head) {
    node *temp;
    while (head->top != NULL) {
        temp = head->top;
        head->top = temp->next;
        free(temp->dp);
        free(temp);
    }
    free(head);
}


        
