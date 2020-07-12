#include <stdio.h>
#define MAX_SIZE 101
//Array implementation of stack
int A[MAX_SIZE];
int top = -1;

void push(int x){
    A[++top] = x;
    return;
}
int pop(){
    if (top == -1){
        printf("Eror: no element to pop\n");
    }
    printf("popped element = %d\n",A[top]);
    int popped = A[top];
    top--;
    return popped; // returns popped element
}
int TOP(){
    return A[top];
}
void print(){
    printf("Current stack - ");
    for(int i=0;i<=top;i++){
        printf(" %d\t",A[i]);
    }
    printf("\n");
}


void main(){
    push(2);
    push(4);
    push(9);
    print();
    int d = pop();
    print();
    printf("%d\n",d);
}
