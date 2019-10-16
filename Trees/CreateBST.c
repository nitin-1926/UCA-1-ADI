#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree* makeNode(int item){
    struct tree *new_node = (struct tree*)malloc(sizeof(struct tree));
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct tree* insertNode(struct tree* root,int item){
    if(root==NULL){
        return makeNode(item);
    }
    if(item < root->data){
        root->left = insertNode(root->left,item);
    }
    if(item > root->data){
        root->right = insertNode(root->right,item);
    }
    return root;
}

int main(){
    struct tree* root = makeNode(50);
    insertNode(root,20);
    insertNode(root,80);
    insertNode(root,10);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,30);
    insertNode(root,90);
    return 0;
}