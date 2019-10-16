#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *prev;
  struct Node *next;
};


struct Node *head = NULL;

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
    struct Node *ptr = *head;
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

void addFirstLastRec(struct Node* node, struct Node** np){
  if(node->next==NULL){
    insertEnd(node->value, np);
  }
  else{
    addFirstLastRec(node->next,np);
    insertEnd(node->value,np);
  }
  
}

struct Node* addFirstLast(struct Node *head){
  struct Node *newLL = NULL;
  struct Node *tmp=NULL;
  addFirstLastRec(head,&tmp);

  int count=0;
  struct Node* ptr=head,*ptr2=tmp;
  while(ptr!=NULL){
    count++;
    ptr=ptr->next;
  }
  ptr = head;
  ptr2=tmp;
  for(int i=0;i<count/2;i++){
    insertEnd(ptr->value+ptr2->value,&newLL);
    ptr2=ptr2->next;
    ptr=ptr->next;
  }
  if(count%2){
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


  printList(head);

  Node* newLL = addFirstLast(head);
  printList(newLL);
  
  return 0;
}
