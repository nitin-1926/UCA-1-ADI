#include <stdio.h>
#include<stdlib.h> 
  

typedef struct Node 
{ 
    struct Node *left, *right; 
    int key; 
}Node ; 
  
Node* newNode(int key) 
{ 
    Node *temp = (Node*) malloc(sizeof(Node)); 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
struct Node *findLCA(struct Node* root, int n1, int n2) 
{ 
    
    if (root == NULL) return NULL;
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
  
    if (left_lca && right_lca)  return root; 
  
    return (left_lca != NULL)? left_lca: right_lca; 
} 
  
int main() 
{  
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    printf("LCA(4, 5) = %d\n",findLCA(root, 4, 5)->key); 
    printf("LCA(4, 6) = %d\n",findLCA(root, 4, 6)->key); 
    printf("LCA(3, 4) = %d\n",findLCA(root, 3, 4)->key); 
    printf("LCA(2, 4) = %d\n",findLCA(root, 2, 4)->key);
    return 0; 
}