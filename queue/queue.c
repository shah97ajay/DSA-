#include <stdio.h>

int queue[10];
int count = 0;

//insertion function
void insert(int x){
    if(count == 10){
        fprintf(stderr, "queue is full\n");
        return;
    }
    else{
        queue[count] = x;
        count++;
    }
}

//deletion function
int delete(){
    if(count == 0){
        fprintf(stderr, "queue is empty\n");
        return -1;
    }
    else{
        int res = queue[0];
        for (int i = 0; i < count -1; i++){
            queue[i] = queue[i+1];
        }
        count--;
        return res;
    }
}

int main (int argc, char* argv[]){
    
    for (int i = 1; i <= 10; i++) 
        insert(i);
    
    printf("Queue has element : ");
    for (int i = 0; i < 10; i++)
        printf("%d ", queue[i]);
    
    printf("\n");
    
    printf("Removing element  : ");
    for (int i = 0; i < 10; i++)
        printf("%d ", delete());
    
    return 0;
}