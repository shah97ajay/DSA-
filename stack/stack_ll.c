#include <stdio.h>
#include <stdlib.h>

#define EMPTY (-1)

typedef struct node{
    int value;
    struct node *next;
}node;

typedef node *stack;

void push(stack *s, int num){
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return;
    
    newnode->value = num;
    newnode->next = *s;
    *s = newnode;
}

int pop(stack *s){
    if (*s == NULL) return EMPTY;
    
    int res = (*s)->value;
    node *tmp = *s;
    *s = (*s)->next;
    free(tmp);
    return res;
}

int main(){
    stack s1 = NULL;
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    
    int pop_res;
    while((pop_res = pop(&s1)) != EMPTY){
        printf("%d ", pop_res);
    }
}