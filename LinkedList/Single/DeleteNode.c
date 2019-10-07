#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertEnd(struct Node** head,int num){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = num;
    node->next = NULL;
    if(*head==NULL){
        *head = node;
        return;
    }
    struct Node* ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = node;
}

struct Node* find(struct Node *head, int data)
{
  struct Node* temp=head;
  struct Node* tempp;
  if(head->data == data)
    return NULL;
  else
  {
    temp = head->next;
    tempp = head;
    while(temp != NULL)
    {
      if(temp->data == data)
        return tempp;
      tempp=temp;
      temp = temp->next;
    }
  }
  return NULL;
}
void deletenode(struct Node** head, struct Node* loc, struct Node* prev)
{
  if(prev ==NULL)
    (*head) = (*head)->next;
  else
    prev->next = loc->next;
  free(loc);
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}
int main()
{
  struct Node* head = NULL;

  insertEnd(&head, 6);    
  insertEnd(&head, 5);    
  insertEnd(&head, 4);    
  insertEnd(&head, 3);    
  insertEnd(&head, 2);
  insertEnd(&head, 1);    
  insertEnd(&head, 0);  

  printf("Linked List = ");
  printList(head);
  deletenode(&head, head->next, head);
  printf("Linked List after deleting 2nd element = ");
  printList(head);
  return 0;
}
