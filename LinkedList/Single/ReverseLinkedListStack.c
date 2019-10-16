#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} Node;



Node *head = NULL;


int stack[100];
int top=-1;



void push(int v){
  top=top+1;
  stack[top]=v;
}

int isEmpty(){
  if(top==-1)
    return 1;
  return 0;
}

int pop(){
  if(top>=0){
  top=top-1;
  return stack[top+1];
  }
  else{
    return -1;
  }
}


Node *createNode(int v, Node *next)
{
  Node *newnode = (Node *)malloc(sizeof(Node *));
  newnode->value = v;
  newnode->next = next;
  return newnode;
}

void insertEnd(int v,Node **head)
{
  Node *newnode = createNode(v, NULL);
  if (*head == NULL){
    *head = newnode;
  }
  else{
    Node *ptr = *head;
    while (ptr->next != NULL){
      ptr = ptr->next;
    }
    ptr->next = newnode;
  }
}

void printList(Node *head)
{
  Node *ptr = head;
  if (head == NULL)
  {
	printf("NULL");
  }
  //return;
  while (ptr != NULL)
  {
	printf("%d",ptr->value);
	ptr = ptr->next;
  }
  printf("\n");
}


void insertBeg(int v, Node** head){
  if(*head==NULL){
    *head=createNode(v,NULL);
  }
  else{
    Node *np = createNode(v,*head);
    *head = np;
  }
  
}

Node *reverseLL(Node *head)
{
	Node *newLL = NULL;
  Node *ptr=head;
  while(ptr!=NULL){
    push(ptr->value);
    ptr=ptr->next;
  }
  while(!isEmpty()){
    insertEnd(pop(),&newLL);
  }
	return newLL;
}


int main()
{
  

  insertEnd(1,&head);
  insertEnd(2,&head);
  insertEnd(3,&head);
  insertEnd(4,&head);
  insertEnd(5,&head);
  insertEnd(5,&head);
  insertBeg(1,&head);
  printList(head);

  
  
	Node *newLL = reverseLL(head);
  printList(newLL);
  
  return 0;
}
