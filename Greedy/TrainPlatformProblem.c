#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    int flag;
};
struct Node* Arrivalhead = NULL;
struct Node* Departurehead = NULL;
struct Node* head = NULL;

void swap(struct Node *p1, struct Node*p2){
	int temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;

    int temp2 = p1->flag;
    p1->flag = p2->flag;
    p2->flag = temp2;
}

struct Node* SelectionSort(struct Node *head){
	struct Node *start = head;
	struct Node *traverse;
	struct Node *min;
	
	while(start->next){
		min = start;
		traverse = start->next;
		
		while(traverse){
			if( min->data > traverse->data ){
				min = traverse;
			}
			traverse = traverse->next;
		}
		swap(start,min);
		start = start->next;
	}
    return head;
}

void print(struct Node* head){
    if(head==NULL){
        printf("Inserted List Empty");
    }
    struct Node* ptr = head;
    while(ptr){
        printf("%d -> ",ptr->flag);
        ptr = ptr->next;
    }
}

void insertEnd(struct Node** head,int num,int val){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = num;
    node->next = NULL;
    node->flag = val;
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

int main(){
    printf("Enter the number of Trains\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Arrival Date of train #%d: ",i+1);
        int arr;
        scanf("%d",&arr);
        insertEnd(&Arrivalhead,arr,1);

        printf("Enter the Departure Date of train #%d: ",i+1);
        int dep;
        scanf("%d",&dep);
        insertEnd(&Departurehead,dep,0);
    }
    head = Arrivalhead;
    struct Node* ptr = head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = Departurehead;
    struct Node* result = SelectionSort(head);
    ptr = result;
    int max = 0;
    int res = 0;
    while(ptr){
        if(ptr->flag == 1){
            max+=1;
            if(max>res){
                res = max;
            }
        }
        if(ptr->flag == 0){
            max-=1;
        }
        ptr = ptr->next;
    }
    printf("\nMinimum Number Of Platforms Required Are: %d\n",res);
    return 0;
}