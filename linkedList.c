#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;               // points to adress of the next node in the list
};

struct node* head = NULL;            // points to the the first node (initially list size 0,then null)


// display list
void printList(){   
    struct node* ptr = head;         // ptr is a pointer to a datatype of (struct node) which points to the head
    printf("\n[");
    while(ptr != NULL){
        printf("%d ",(*ptr).data);   //(*ptr).data is same as ptr->data  
        ptr = (*ptr).next;           //  which says go to struct node ptr and access .data
    }
    printf("]");
}

void insertFirst(int data){          //inserts node to the starting of the list
    struct node* link = (struct node*)malloc(sizeof(struct node)); // create a link ie temp
    link->data = data;
    link->next = head;                  // point link to old first node

    head = link;                       // point head to new first node
}


void insertNth(int data,int n){
    struct node* temp1 = (struct node*)malloc(sizeof(struct node*));
    temp1->data = data;
    temp1->next= NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    struct node* temp2 = (struct node*)malloc(sizeof(struct node*));
    temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2 = temp2->next;

    }
    temp1->next = temp2->next;
    temp2->next = temp1;
  
}

void deleteNth(int n){
    struct node* temp  = (struct node*)malloc(sizeof(struct node*));
    struct node* temp2 = (struct node*)malloc(sizeof(struct node*));

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
    struct node* ctr = head;
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