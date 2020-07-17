#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;               // points to adress of the next node in the list
};

struct Node* head = NULL;            // points to the the first node (initially list size 0,then null)


// display list
void printList(){   
    struct Node* ptr = head;         // ptr is a pointer to a datatype of (struct node) which points to the head
    printf("\n[");
    while(ptr != NULL){
        printf("%d ",(*ptr).data);   //(*ptr).data is same as ptr->data  
        ptr = (*ptr).next;           //  which says go to struct node ptr and access .data
    }
    printf("]");
}

void insertFirst(int data){          //inserts node to the starting of the list
    struct Node* link = (struct Node*)malloc(sizeof(struct Node)); // create a link ie temp
    link->data = data;
    link->next = head;                  // point link to old first node

    head = link;                       // point head to new first node
}


void insertNth(int data,int n){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = data;
    temp1->next= NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node*));
    temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2 = temp2->next;

    }
    temp1->next = temp2->next;
    temp2->next = temp1;
  
}

void deleteNth(int n){
    struct Node* temp  = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node*));

    temp = head;                // temp points to the first node
   
    if (n==1){
        head = temp->next;
        free(temp);
        return;
    }
    for (int i =0;i<n-2;i++){
        temp = temp->next;        // temp  points to n-1th node
    }
    temp2 = temp->next;           // temp2 points to nth   node
    temp->next = temp2->next;     // temp  points to n+1th node
    free(temp2);
}

void insertLast(int data){
    int t = 0;
    struct Node* ctr = head;
    while(ctr != NULL){
        ctr = ctr->next;
        t++;
    }
    insertNth(data,t+1);
    return;
}    

void main(){
    insertFirst(1);
    insertFirst(2);
    insertFirst(3);


    
    printList();
    insertLast(9);
    printList();

    
}