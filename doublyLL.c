#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

struct Node* getNewNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next =  NULL;
    return newNode;
}
void insertFirst(int data){
    struct Node* temp = getNewNode(data);
    if(head == NULL ){
        head = temp;
        return;
    }
    //
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void print(){
    struct Node* tmp = head;
    
    while(tmp!=NULL ){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void revPrint(){
    struct Node* tmp = head;
    if(tmp == NULL){
        return;
    }
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }

    while (tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp = tmp->prev;
    }
    
    
}

void main(){
    insertFirst(2);
    insertFirst(4);
    insertFirst(6);
    print();
    insertFirst(8);
    revPrint();

}