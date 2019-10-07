#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

int  checkPalindrome(struct Node* head) 
{
  int size=0;
  int flag=0;
	struct Node* tail = NULL;
  struct Node* ptr = head;
  struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
  while(ptr){
    if(ptr==head){
      head2->data = ptr->data;
      head2->next=NULL;
      ptr = ptr->next;
    }
    else{
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->next= head2 ;
      new_node->data = ptr->data;
      head2 = new_node;
      ptr=ptr->next;
    }
  }
  struct Node* ptr2 = head2;
  ptr = head;
  while(ptr&&ptr2){
    if(ptr->data==ptr2->data){
      flag = 1;
      ptr = ptr->next;
      ptr2 = ptr2->next;
    }
    else{
      flag = 0;
      break;
    }
  }
  return flag;
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
  printf("Enter the no. of test cases\n");
  scanf("%d",&t);
  while(t!=0){
  	struct Node* head = NULL;
    int n;
    printf("Enter the number of elements in the linked list\n");
    scanf("%d",&n);
    if(n==0){
        printf("Cannot execute Function as their will be No List\n");
        break;
    }
    head = makelist(n);
    int ret = checkPalindrome(head);
    if(ret == 0)
    	printf("Given List is Not a Palindrome");
    if(ret == 1)
    	printf("Given List is a Palindrome");
    t--;
  }
  return 0;
}