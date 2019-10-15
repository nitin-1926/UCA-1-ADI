#include<stdio.h>
#include<stdlib.h> 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
void printList(struct Node* node){ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

struct Node* SortedMerge(struct Node* a, struct Node* b) { 
    struct Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if(b == NULL) 
        return (a); 
  
    if(a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else{ 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return result; 
} 

struct Node* mergeKLists(struct Node* arr[], int last) 
{   while (last != 0) { 
        int i = 0, j = last; 
        while (i < j){
            arr[i] = SortedMerge(arr[i], arr[j]); 
            i++, j--; 
            if (i >= j) 
                last = j; 
        } 
    } 
    return arr[0]; 
} 
  
struct Node *newNode(int data) { 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 
int main() { 
    int k = 3; 
    int n = 4;  
    struct Node* arr[k]; 
  
    arr[0] = newNode(1); 
    arr[0]->next = newNode(3); 
    arr[0]->next->next = newNode(5); 
    arr[0]->next->next->next = newNode(7); 
  
    arr[1] = newNode(2); 
    arr[1]->next = newNode(4); 
    arr[1]->next->next = newNode(6); 
    arr[1]->next->next->next = newNode(8); 
  
    arr[2] = newNode(0); 
    arr[2]->next = newNode(9); 
    arr[2]->next->next = newNode(10); 
    arr[2]->next->next->next = newNode(11); 
  
    struct Node* head = mergeKLists(arr, k - 1); 
    printList(head); 
    return 0; 
} 