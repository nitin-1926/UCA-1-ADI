/*
Given a single linked list and an integer x. Your task is to complete the function deleteAllOccurances() which deletes all occurences of a key x present in the linked list. The function takes two arguments: the head of the linked list and an integer x. The function should return the head of the modified linked list.

Input:
The first line of input contains an element T, denoting the number of test cases. Then T test cases follow. Each test case contains three lines. The first line of each test case contains an integer N denoting the no of elements of the linked list. Then in the next line are N space separated values of the linked list. The third line of each test case contains an integer x.

Output:
The output for each test case will be the space separated value of the returned linked list.

User Task:
The task is to complete the function deleteAllOccurances() which should delete all the occurrences of given number x from the list.

Constraints:
1 <= T <= 300
1 <= N <= 100
1 <= x <= N

Example:
Input:
2
5
2 2 1 4 4
4
6
1 2 2 3 2 3
2

Output:
2 2 1
1 3 3

Example:
Testcase 2: Given number to delete is 2. After deleting all occurrences of 2, we have elements in the list as 1, 3, and 3.
*/

// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

  // TO BE REMOVED
  for (int i=0; i<2000; i++);


    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}

// } Driver Code Ends
/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here
    if(head==NULL){
        return NULL;
    }
    if(head->data==x && head->next==NULL){
        return NULL;
    }
    while(head->data == x){
        head=head->next;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data == x){
            temp->next = temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
