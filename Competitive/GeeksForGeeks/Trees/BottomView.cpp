/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Input Format:

First line of input contains the number of test cases T. For each test case, there will be two lines: 

First line of each test case will be an integer N denoting the number of parent child relationships.
Second line of each test case will print the level order traversal of the tree in the form of N space-separated triplets. The description of triplets is as follows:
​​Each triplet will contain three space-separated elements of the form (int, int, char).
The first integer element will be the value of parent. 
The second integer will be the value of corresponding left or right child. In case the child is null, this value will be -1.
The third element of triplet which is a character can take any of the three values ‘L’, ‘R’ or ‘N’. L denotes that the children is a left child, R denotes that the children is a Right Child and N denotes that the child is NULL.
Please note that the relationships are printed only for internal nodes and not for leaf nodes.  

Output Format:
The function should print nodes in the bottom view of Binary Tree. Your code should not print a newline, it is added by the caller code that runs your function.

User Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which should print the bottom view of the given tree.

Constraints:
1 <= T<= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 3 L 1 2 R
8
4 5 L 4 4 R 5 2 L 5 7 R 4 -1 N 4 7 R 2 6 L 2 3 R
Output:
3 1 2
6 2 3 7 4 7

Explanation:
Testcase 1:  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.


Thus nodes of the binary tree will be printed as such 3 1 2.
*/
// { Driver Code Starts
// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that prints the bottom view.
void bottomView(Node *root);

Node* make_tree()
{
	int n;
	cin>>n;
	
    
	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-- )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}
		
		n--;
		if(!n) break;
		
		cin>> a >> b >> c;
		
		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     
     Node* root = make_tree();
     bottomView(root);
     cout << endl;
  }
  return 0;
}

// } Driver Code Ends
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that prints the bottom view.
void bottomView(Node *root)
{
   // Your Code Here
   if(root == NULL){
       return;
   }
   queue < pair<Node*,int> >q;
   pair <Node*,int> p;
   p.first = root;
   p.second = 0;
   map<int,int> m;
   q.push(p);
   while(!q.empty()){
       pair <Node*,int> l = q.front();
       q.pop();
       Node* temp = l.first;
       int hd = l.second;
       
       m[hd] = temp->data;
       if(temp->left){
           pair <Node*,int> z;
           z.first = temp->left;
           z.second = hd-1;
           q.push(z);
       }
       if(temp->right){
           pair <Node*,int> z;
           z.first = temp->right;
           z.second = hd+1;
           q.push(z);
       }
   }
   for(auto i = m.begin();i!=m.end();i++){
       cout<<i->second<<" ";
   }
}

