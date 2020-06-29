#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x){
    A[++top] = x;
    return;
}
void pop(){
    if (top == -1){
        printf("Eror: no element to pop\n");
    }
    printf("popped el = %d\n",A[top]);
    top--;
}
int TOP(){
    return A[top];
}
void print(){
    for(int i=0;i<=top;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}


void main(){
    push(2);
    push(4);
    push(9);
    print();
    pop();
    print();
}
