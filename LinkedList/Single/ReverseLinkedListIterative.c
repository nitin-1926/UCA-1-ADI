#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} Node;


Node *head = NULL;

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
	Node *newLL =  (Node *)malloc(sizeof(Node *));
  Node *ptr=head;
  while(ptr!=NULL){
		insertBeg(ptr->value,&newLL);
    ptr=ptr->next;
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
