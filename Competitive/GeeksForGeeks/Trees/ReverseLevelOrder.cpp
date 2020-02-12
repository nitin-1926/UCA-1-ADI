/*

Given below is a tree. The task is to print the Reverse Level Order Traversal of the given tree. You will be given a function reversePrint(), which accepts root of the tree as argument.
                                              
                                           

 

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains number of edges. The second line contains number of edges+1 data of nodes of tree separated by space.

Output:
For each testcase in new line, print the reverse level order traversal of tree separated by space.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function reversePrint().

Constraints:
1 <= T <= 30
1 <= Number of edges <= 3*103
1 <= Data of a node <= 3*103

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 2 1
40 60 20 30 10

Explanation:
Testcase 1: There are total 3 nodes of tree.

Reverse level order traversal of tree is: 3 2 1.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void reversePrint(Node *root);

/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

   reversePrint(root);
   cout<<endl;

  }
    return 0;
}


// } Driver Code Ends
/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


void reversePrint(Node *root)
{
    //Your code here
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    stack<int>s;
    q.push(root);
    while(q.empty()==NULL){
        Node* temp = q.front();
        q.pop();
        s.push(temp->data);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
    }
}
