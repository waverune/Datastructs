#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));

    temp->data = data;
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

void printList(){   
    struct node* ptr = head;         // ptr is a pointer to a datatype of (struct node) which points to the head
    printf("\n[");
    while(ptr != NULL){
        printf("%d ",(*ptr).data);   //(*ptr).data is same as ptr->data  
        ptr = (*ptr).next;           //  which says go to struct node ptr and access .data
    }
    printf("]");
}



void main(){
    push(9);
    push(8);
    pop();
    pop();
    
    printList();

}