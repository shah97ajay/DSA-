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

//Insert after root node
void insert_after(node* head, int x){
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL){
        fprintf(stderr, "malloc failed");
        return;
    }
    newnode->value = x;
    newnode->next = head->next;
    head->next = newnode;
}


void insert_sorted(node** head, int x){
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL){
        fprintf(stderr, "malloc failed");
        return;
    }
    
    if ((*head) == NULL || (*head)->value >= x){
        insert_beginning(head, x);
        return;
    }

    node* temp = (*head);
    while(temp->next != NULL){
        if (temp->next->value <= x){
            temp = temp->next;
        }else break;
    }
    insert_after(temp, x);
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
    
    insert_sorted(&new, 2);
    insert_sorted(&new, 1);
    insert_sorted(&new, 5);
    insert_sorted(&new, 3);

    print(new);
    
    return 0;
}