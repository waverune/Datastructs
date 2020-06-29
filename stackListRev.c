#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
    int ch;
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

void printList(){   
    struct node* ptr = head;         // ptr is a pointer to a datatype of (struct node) which points to the head
    printf("\n[");
    while(ptr != NULL){
        printf("%d ",(*ptr).ch);   //(*ptr).data is same as ptr->data  
        ptr = (*ptr).next;           //  which says go to struct node ptr and access .data
    }
    printf("]");
}


void main(){
push(2);
push(5);
push(3);
push(8);
printList();
}