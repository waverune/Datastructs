#include <stdio.h>
#include <stdlib.h>
//stack implemented using linkedlist
//LIFO
struct Node{
    int data;
    struct Node* next;       // pointer to the next node
};

struct Node* head = NULL;

void push(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));

    temp->data = data;
    temp->next = head;
    head = temp;
}
int pop(){
    if(head == NULL){
        printf("ERROR empty stack\n");
        return 0;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp = head;
    head = temp->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void printList(){   
    struct Node* ptr = head;         // ptr is a pointer to a datatype of (struct node) which points to the head
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
    push(9);
    pop();
    pop();
    pop();

    printList();

}