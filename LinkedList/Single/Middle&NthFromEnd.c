#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

int findMiddle(struct Node* head) 
{
  if(head==NULL){
    return -1;
  }
  int size=0;
  struct Node* ptr = head;
  while(ptr){
    ptr=ptr->next;
    size++;
  }
  ptr=head;
  if(size%2==1){
    	for(int i=1;i<=size/2;i++){
          ptr = ptr->next;
        }
    	return ptr->data;
	}
    if(size%2==0){
    	for(int i=1;i<size/2+1;i++){
          ptr = ptr->next;
        }
    	return ptr->data;
	}
}

int findNLast(struct Node* head, int n)
{
  if(head==NULL){
    return -1;
  }
  int size=0;
  int count;
  struct Node* ptr = head;
  while(ptr->next){
    ptr=ptr->next;
    size++;
  }
  if(n>size+1){
    return ptr->data;
  }
  else
  {
    count = size+1-n;
    ptr=head;
    for(int i=1;i<=count;i++){
      ptr=ptr->next;
    }
    return ptr->data;
  }
}

struct Node* makelist(int n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = NULL;

	for (int i = 0; i < n; i++){
      if(ptr == NULL)
      {
        scanf("%d",&temp->data);
        ptr = temp;
      }
      else{
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        ptr->next=new_node;
        scanf("%d",&new_node->data);
        ptr = new_node;
        ptr->next = NULL;
      }
    }
    return temp;
}
int main(){
  int t;
  printf("Enter the number of test cases\n");
  scanf("%d",&t);
  while(t!=0){
  	struct Node* head = NULL;
    int n;
    printf("Enter the number of elements present in the linked list\n");
    scanf("%d",&n);
    if(n==0){
        printf("Cannot execute Function as their will be No List\n");
        break;
    }
    head = makelist(n);
    int mid = findMiddle(head);
    printf("The Middle Element is: %d\n",mid);
    printf("Enter the number to get from End\n");
    int number;
    scanf("%d",&number);
    int ret = findNLast(head,number);
    printf("The Nth Element from End is: %d\n",ret);
    t--;
  }
  return 0;
}