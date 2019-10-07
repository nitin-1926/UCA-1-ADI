#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node* head = NULL;

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

int detectloop(struct Node* head) 
{ 
    struct Node *slow = head, *fast = head; 
  
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
            return 1; 
        } 
    } 
    return 0; 
} 

int main(){
    printf("Enter the number of elements in the Linked List\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        insertEnd(&head,num);
    }

    //Add the below line for loop and remove to remove loop
    head->next->next = head;
    
    int f = detectloop(head);
    printf("%d",f);
    if(f==0){
        printf("No Loop Detected");
    }
    else{
        printf("Loop Detected");
    }
    return 0;
}