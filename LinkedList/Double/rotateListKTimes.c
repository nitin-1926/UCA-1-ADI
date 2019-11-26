/* struct Node
{
    int data;
    struct Node *next;
  	struct Node *prev;
};

Above structure is used to define the linked list, You have to complete the below functions only */

struct Node* rotateByK(struct Node* head, int k)
{
  struct Node* ptr = head;
  int size=0;
  while(ptr){
    size++;
    ptr = ptr->next;
  }
  if(head == NULL || k==0 || k==size){
    return head;
  }
  int skip = size-k;
  ptr = head;
  struct Node* end = NULL;
  for(int i=0;i<skip-1;i++){
    ptr = ptr->next;
  }
  end = ptr;
  struct Node* begin = end->next;
  end->next = NULL;
  
  ptr = begin;
  while(ptr->next){
    ptr = ptr->next;
  }
  ptr->next = head;
  head->prev = ptr;
  return begin;
}