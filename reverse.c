#include <stdio.h>
#include <string.h>
#define MAX 101

char A[MAX];
int top = -1;

void push(char c){
    A[++top] = c;
    return;
}

char pop(){
    if(top == -1){
        printf("ERROR\n");
        return 'e';
    }
    char popped = A[top];  
    top--;
    return popped;
}

char TOP(){
    
    return A[top];

}

void rev(char str[],int n){
    for (int i=0;i<n;i++){
        push(str[i]);    // pushes chars into our stack
    }
    for (int i=0;i<n;i++){
        str[i] = TOP();
        pop();
    }
    return ;
}
void print(){
    printf("Current stack - ");
    for(int i=0;i<=top;i++){
        printf("%c\t",A[i]);
    }
    printf("\n");
}

void main(){
    char* str[51];
    scanf("%s",&str);
    int n = strlen(str);
  //str[1]='i';
    rev(str,n);
    printf("reverse - %s\n",str);
    


}