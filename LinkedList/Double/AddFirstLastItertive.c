#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *prev;
  struct Node *next;
};


struct struct Node *head = NULL;

struct Node *createNode(int v,struct Node* prev, struct Node *next)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->value = v;
  newnode->prev=prev;
  newnode->next = next;
  return newnode;
}

void insertEnd(int v,struct Node **head)
{
  struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
  if (*head == NULL){
    newnode = createNode(v, NULL , NULL);
    *head = newnode;
  }
 
  else{
    Node *ptr = *head;
    while (ptr->next!= NULL){
      ptr = ptr->next;
    }
    newnode = createNode(v, ptr , NULL);
    ptr->next = newnode;
  }
}

void printList(struct Node *head)
{
  struct Node *ptr = head;
  if (head == NULL)
  {
    return;
  }
  while (ptr != NULL)
  {
  	printf("%d",ptr->value);
	  ptr = ptr->next;
  }
  printf("\n");
}

struct Node* addFirstLast(struct Node *head){
  struct Node *slow=head, *fast = head;
  struct Node *newLL = NULL;
  if(head==NULL){
    return NULL;
  }
  struct Node *tmp=head;
  while( fast!=NULL && fast->next!=NULL ){

    if(fast->next->next==NULL){
      slow=slow->next;
      fast = fast->next;
      continue;
    }
    tmp=tmp->next->next;
    slow=slow->next;
    fast=fast->next->next;
  }
  
  struct Node* ptr=head;
    
  while(ptr != slow && ptr!=NULL){
    insertEnd(ptr->value+fast->value,&newLL);
    ptr=ptr->next;
    fast=fast->prev;
  }
  if(tmp->next == NULL){
    insertEnd(ptr->value,&newLL);
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
  insertEnd(6,&head);

  printList(head);

  struct Node* newLL = addFirstLast(head);
  printList(newLL);
  
  return 0;
}
