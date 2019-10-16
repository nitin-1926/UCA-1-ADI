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

// Node *mergingPoint(Node* h1, Node* h2){
//   int hash[10000]={0};
//   Node *ptr=h1;
//   while(ptr!=NULL){
//     hash[hashKey(ptr)]++;
//     ptr=ptr->next;
//   }
//   ptr=h2;
//   while(ptr!=NULL){
//     if(hash[hashKey(ptr)] != 0){
//       printf("%d  ",hashKey(ptr));
//       return ptr;
//     }
//     ptr=ptr->next;
//   }
//   return NULL;
// }



int getCount(Node* head) 
{ 
    Node* current = head; 
  
    // Counter to store count of nodes 
    int count = 0; 
  
    // Iterate till NULL 
    while (current != NULL) { 
  
        // Increase the counter 
        count++; 
  
        // Move the Node ahead 
        current = current->next; 
    } 
  
    return count; 
} 




Node* _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 

    Node* current1 = head1; 
    Node* current2 = head2; 

    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return NULL; 
        } 
        current1 = current1->next; 
    } 

    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1;
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return NULL; 
} 

Node* getIntesectionNode(Node* head1, Node* head2) 
{ 
  
    // Count the number of nodes in 
    // both the linked list 
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    // If first is greater 
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntesectionNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntesectionNode(d, head2, head1); 
    } 
} 






Node *h2=NULL;
int main()
{

  insertEnd(2,&head);
  insertEnd(3,&head);
  insertEnd(4,&head);
  insertEnd(5,&head);
  insertEnd(5,&head);


  insertEnd(2,&h2);
  insertEnd(3,&h2);
  insertEnd(4,&h2);
  insertEnd(5,&h2);
  insertEnd(5,&h2);


  printList(h2);

  Node *mergePoint=NULL;
  mergePoint = getIntesectionNode(head, h2);
  
  if(mergePoint == NULL){
    printf("Not Intersecting\n");
  }
  else{
    printf("Intersecting at %d\n",mergePoint->value);
  }
  
  return 0;
}
