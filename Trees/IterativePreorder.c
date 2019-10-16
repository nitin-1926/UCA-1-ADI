#include <stdio.h>
#include<stdlib.h>
#include<math.h>
  
struct node{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
 
#define STACK_SIZE 10
  
typedef struct stack{
        int top;
        Node *items[STACK_SIZE];
}stack;
  
void push(stack *ms, Node *item){
   if(ms->top < STACK_SIZE-1){
       ms->items[++(ms->top)] = item;
   }
   else {
       printf("Stack is full\n");
   }
}
  
Node * pop (stack *ms){
   if(ms->top > -1 ){
       return ms->items[(ms->top)--];
   } 
   else{
       printf("Stack is empty\n");
   }
}
Node * peek(stack ms){
  if(ms.top < 0){
      printf("Stack empty\n");
      return 0;
   }
   return ms.items[ms.top];
}
int isEmpty(stack ms){
   if(ms.top < 0) return 1;
   else return 0;
}
void preorderTraversal(Node *root){
    stack ms;
    ms.top = -1;
     
    if(root == NULL) return ;
 
    Node *currentNode = NULL;
    push(&ms,root);
     
    while(!isEmpty(ms)){
        currentNode = pop(&ms);
        printf("%d  ", currentNode->value);
        if(currentNode->right){
            push(&ms, currentNode->right);
        }
        if(currentNode->left){
            push(&ms, currentNode->left);
        }
    }
}
  
Node * createNode(int value){
    Node * newNode =  (Node *)malloc(sizeof(Node));
     
    newNode->value = value;
    newNode->right= NULL;
    newNode->left = NULL;
     
    return newNode;
}
 
Node * addNode(Node *node, int value){
    if(node == NULL){
        return createNode(value);
    }
    else{
        if (node->value > value){
            node->left = addNode(node->left, value);
        }
        else{
            node->right = addNode(node->right, value);
        }
    }
    return node;
}
  
int main(){
        Node *root = NULL;
        root = addNode(root,30);
        root = addNode(root,20);
        root = addNode(root,15);
        root = addNode(root,25);
        root = addNode(root,40);
        root = addNode(root,37);
        root = addNode(root,45);
     
        preorderTraversal(root);
        return 0;
}