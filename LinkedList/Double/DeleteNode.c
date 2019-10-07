#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void deletenode(struct Node** head, struct Node* loc)
{
  if(loc->prev ==NULL) {
    (*head) = (*head)->next;
    (*head)->next->prev=NULL;
  }
  else
    loc->prev->next = loc->next;
  loc->next->prev = loc->prev;
}

void insertEnd(struct Node** head,int num){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = num;
    node->next = NULL;
    node->prev = NULL;
    if(*head==NULL){
        *head = node;
        return;
    }
    struct Node* ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = node;
    node->prev = ptr;
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
  deletenode(&head, head->next);
  printf("Linked List after deleting 2nd element = ");
  printList(head);

  return 0;
}
