#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
} node;

//Insert at last of linked list
void insert_last(node** head, int x){
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL){
        fprintf(stderr, "malloc failed");
        return;
    }
    
    newnode->value = x;
    newnode->next = NULL;
    
    if (*head == NULL){
        *head = newnode;
        return;
    }
    
    node* temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}

//Insert at beginning of linked list
void insert_beginning(node** head, int x){
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL){
        fprintf(stderr, "malloc failed");
        return;
    }
    newnode->value = x;
    newnode->next = *head;
    *head = newnode;
}

//Print the linked list
void print(node* head){
    while (head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
}


int main(){
    node* new = NULL;
    
    insert_last(&new, 2);
    insert_last(&new, 3);
    insert_last(&new, 4);

    insert_beginning(&new, 1);
    insert_beginning(&new, 0);

    print(new);
    
    return 0;
}