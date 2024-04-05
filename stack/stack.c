#include <stdio.h>

int stack[10];
int count = 0;

//push function
void push(int x){
    if(count == 10){
        fprintf(stderr, "stack is full\n");
        return;
    }
    else{
        stack[count] = x;
        count++;
    }
}

//pop function
int pop(){
    if(count == 0){
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    else{
        int res = stack[count - 1];
        count--;
        return res;
    }
}

int main (int argc, char* argv[]){
    
    for (int i = 1; i <= 10; i++) 
        push(i);
    
    printf("Stack has element : ");
    for (int i = 0; i < 10; i++)
        printf("%d ", stack[i]);
    
    printf("\n");
    
    printf("Removing element  : ");
    for (int i = 0; i < 10; i++)
        printf("%d ", pop(i));
    
    return 0;
}