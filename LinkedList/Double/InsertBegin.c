#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

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

struct Node* makeNode(int num){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = num;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
struct Node* insertBegin(struct Node** head,struct Node* node){
    if(*head==NULL){
        *head = node;
        return *head;
    }
    node->next = *head;
    (*head) -> prev = node;
    *head = node;
    return *head;
}

int main(){
    printf("Enter the number of elements in the linked List\n");
    int n;
    scanf("%d",&n);
    struct Node* head = NULL;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        struct Node* temp = makeNode(num);
        insertBegin(&head,temp);
    }
    print(head);
    return 0;
}