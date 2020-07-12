#include <stdio.h>
#include <stdlib.h>
//stack implemented using linkedlist
struct node{
    int data;
    struct node* next;       // pointer to the next node
};

struct node* head = NULL;

void push(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));

    temp->data = data;
    temp->next = head;
    head = temp;
}
int pop(){
    if(head == NULL){
        printf("ERROR empty stack\n");
        return 0;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp = head;
    head = temp->next;
    int popped = temp->data;
    free(temp);
    return popped;
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
    push(12);
    push(8);
    push(11);
    pop();
    pop();
    pop();

    printList();

}