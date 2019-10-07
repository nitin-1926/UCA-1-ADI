#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertBegin(struct Node** head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  struct Node* t = *head;
  node->data  = data;
  node->next = *head;
  if (*head != NULL)
  {
    while(t->next != *head)
      t = t->next;
    t->next = node;
  }
  else
    node->next = node;
  *head = node;
}

void print(struct Node *first)
{
  struct Node *temp = first;
  if (first != NULL)
  {
    do
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    while (temp != first);
  }
  printf("\n");
}

int main(){
    printf("Enter the number of elements in the linked List\n");
    int n;
    scanf("%d",&n);
    struct Node* head = NULL;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        insertBegin(&head,num);
    }
    print(head);
    return 0;
}
