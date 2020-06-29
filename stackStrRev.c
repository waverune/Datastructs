#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
    char ch;
    struct node* next;
};

struct node* head = NULL;

void push(char ch){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));

    temp->ch = ch;
    temp->next = head;
    head = temp;
}

void pop(){
    if(head == NULL){
        printf("ERROR\n");
        return;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp = head;
    head = temp->next;
    free(temp);

}
char top(){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp = head;

    return temp->ch;
}

void reverse(char str[],int n){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
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