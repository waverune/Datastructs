#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node{
    char ch;
    struct Node* next;
};

struct Node* head = NULL;

void push(char ch){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));

    temp->ch = ch;
    temp->next = head;
    head = temp;
}

void pop(){
    if(head == NULL){
        printf("ERROR\n");
        return;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp = head;
    head = temp->next;
    free(temp);

}
char top(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp = head;

    return temp->ch;
}

void reverse(char str[],int n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp = head;
    for (int i=0;i<n;i++){
        push(str[i]);
    }
    for (int i = 0;i<n;i++){
        str[i]=top();
        pop();
    }


}


void main(){
    char str[]="hello";
    int n = strlen(str);
    reverse(str,n);
    for(int i=0;i<n;i++){
        printf("%c",str[i]);
    }

}