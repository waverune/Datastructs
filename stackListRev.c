#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node{
    int ch;
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

void printList(){   
    struct Node* ptr = head;         // ptr is a pointer to a datatype of (struct node) which points to the head
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