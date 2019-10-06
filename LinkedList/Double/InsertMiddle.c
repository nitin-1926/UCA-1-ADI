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

void insertMiddle(struct Node** head, int n, int k){
    if(*head==NULL){
        return;
    }
    struct Node* ptr = *head;
    for(int i=0;i<k-1;i++){
        ptr = ptr->next;
    }
    struct Node* temp = ptr->next;

    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = n;
    node->next = NULL;

    ptr->next = node;
    node->prev = ptr;
    node->next = temp;
    node->next->prev = node;
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
    printf("Enter the number of the node After which you want to insert\n");
    int k;
    scanf("%d",&k);
    printf("Enter the number you want to insert\n");
    int no;
    scanf("%d",&no);
    insertMiddle(&head,no,k);
    print(head);
    return 0;
}