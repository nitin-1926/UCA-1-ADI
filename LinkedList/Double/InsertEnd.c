#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node* head = NULL;

void print(struct Node* head){
    if(head==NULL){
        printf("Linked List Empty");
    }
    struct Node* ptr = head;
    while(ptr){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
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

int main(){
    printf("Enter the number of elements in the Linked List\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        insertEnd(&head,num);
    }
    print(head);
    return 0;
}