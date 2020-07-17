#include <stdio.h>
#include <stdlib.h>

struct bstNode{
    int data;
    struct bstNode* left;
    struct bstNode* right;
};
struct bstNode* root = NULL;

struct bstNode* getNewNode(int data){
    struct bstNode* newNode = (struct bstNode*)(malloc(sizeof(struct bstNode*)));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct bstNode* insert(struct bstNode* root,int data){
    struct bstNode* temp = getNewNode(data);
    if(root == NULL){
        root = temp;
        return root;
    }
    else if(data <= root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;

}
int search(struct bstNode* root,int data){
    if (root == NULL){
        return 0;
    }
    else if(root->data = data){
        return 1;
    }
    else if (data <= root->data ){
        return search(root->left,data);
    }
    else {
        return search(root->right,data);
    }
    
}
void print(){
    struct  bstNode* tmp = root;
    printf("\t\t\t%d\n\t\t \n",tmp->data);
    do{

    }
    while(tmp != NULL);

        
        
        
        
    
}

void main(){
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    int d = search(root,20);
    print();
}

