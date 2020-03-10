/*
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Input:
You have to complete the method which takes 3 argument: the head of the first linked list , the head of second linked list and the head of the third link list which is to be created. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Complete the Function given to produce the desired list with intersectioned values.

User Task:
The task is to complete the function intersection() which should find the intersection of two linked list and add all the elements in intersection to the third linked list.

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 1000

Example:
Input:
1
5 4
1 2 3 4 6
2 4 6 8
4 2
10 20 40 50
15 40

Output:
2 4 6
40

Explanation:
Testcase 1: For the given first two linked list, 2, 4 and 6 are the elements in the intersection.
*/

// { Driver Code Starts
/*
Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, then your function should create and return a third list as 2->4->6.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    struct Node *next;
    
    Node(int data){
        val = data;
        next = NULL;
    }
    
};

void push(struct Node **root,int data)
{
    Node *newnode=new Node(data);
    struct Node *prev;
    prev=*root;
    
    if(*root==NULL)
    {
        *root=newnode;
        return;
    }
    while(prev->next!=NULL)
        prev=prev->next;

    prev->next=newnode;
}

void print(struct Node *ptr)
{
    if(ptr==NULL)
    {
        cout<<"NO"<<endl;
        return;
    }
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void intersection(struct Node **head1,struct Node **head2,struct Node **head3);

int main()
{
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    struct Node *head3=NULL;
    int t,n1,n2;
    cin>>t;
    while(t--)
    {
        struct Node *head1=NULL;
        struct Node *head2=NULL;
        struct Node *head3=NULL;
        cin>>n1>>n2;
        int k;
        for(int i=0;i<n1;i++)
        {
            cin>>k;
    
            push(&head1,k);
        }
    
        for(int i=0;i<n2;i++)
        {
            cin>>k;
            push(&head2,k);
             
        }
           
        intersection(&head1,&head2,&head3);
        print(head3);
      
    }
}
// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int val;
    struct Node *next;
    
    Node(int data){
        val = data;
        next = NULL;
    }
    
}; 
*/

void intersection(Node **head1, Node **head2,Node **head3)
{
    // Your Code Here
    if(*head1 == NULL || *head2==NULL){
        return;
    }
    map<int,int> hash;
    Node* ptr = *head1;
    while(ptr){
        hash[ptr->val] = 1;
        ptr=ptr->next;
    }
    ptr = *head2;
    while(ptr){
        if(hash[ptr->val] == 1){
            push(&*head3,ptr->val);
            hash[ptr->val] = 0;
        }
        ptr=ptr->next;
    }
}
