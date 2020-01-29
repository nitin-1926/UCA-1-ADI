/*
Given an array of size N containing level order traversal of a BST. The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) from its given level order traversal.

Input:
First line of input contains number of testcases T. For each testcase, first line contains number of elements and next line contains n elements which is level order travesal of a BST.

Output:
For each test return the pointer to the root of the newly constructed BST.

User Task:
Your task is to complete the function constructBst() which has two arguments, first as the array containing level order traversal of BST and next argument as the length of array.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output:
7 4 3 1 6 5 12 8 10
1 3 4 6 7 8

Explanation:
Testcase 1: After constructing BST, the preorder traversal of BST is 7 4 3 1 6 5 12 8 10.


*/

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function
Node* Lot(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data <= root->data) 
        root->left = Lot(root->left, data); 
    else
        root->right = Lot(root->right, data); 
    return root;
}
Node* constructBst(int arr[], int n)
{
    if(n==0){
        return NULL;
    }
    Node* root = NULL;
    for(int i=0;i<n;i++)
        root = Lot(root,arr[i]);
    return root;
}
