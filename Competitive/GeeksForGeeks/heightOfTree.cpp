/*
Given a binary tree, find height of it.

        1
     /     \
   10      39
  /
5
The above tree has a height of 3.
Note: Height of empty tree is considered 0.

Input Format:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output Format:
For each testcase, in a new line, print the height of tree.

Your Task:
You don't have to take input. Complete the function height() that takes node as parameter and returns the height. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
Sum of N over all testcases doesn't exceed 105

Example:
Input:
3
1 2 3
2 N 1 3 N
10 20 30 40 60 N N
Output:
2
3
3
Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
So, the height would be 2.
Testcase2: The tree is
                           2
                              \
                               1 
                              /    
                          3
So, height would be 3.
Testcase3: The tree is

                           10
                        /        \
                     20         30
                  /       \
               40       60

So, height would be 3.

Note:The Input/Ouput format and Example given are used for system's internal purpose, and 
should be used by a user for Expected Output only. As it is a function problem, hence a user 
should not read any input from stdin/console. The task is to complete the function specified, 
and not to write the full code.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int height(struct Node* node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<height(root)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

/* Computes the height of binary tree with given root.  */
int max(int a, int b){
    if(a>b){return a;}
    return b;
}
int height(Node* node)
{
   // Your code here
   if(node == NULL){
       return 0;
   }
   int l = height(node->left);
   int r = height(node->right);
   
   return max(l,r)+1;
}

