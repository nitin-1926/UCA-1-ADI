/* Top View */
// { Driver Code Starts
#include <bits/stdc++.h>
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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends
//Structure of binary tree
/*struct Node
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
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    if(root == NULL){
        return;
    }
    queue< pair<Node*,int> >q;
    map<int,int> m;
    pair <Node*, int> p;
    p.first = root;
    p.second = 0;
    q.push(p);
    while(!q.empty()){
        pair <Node*, int> l = q.front();
        q.pop();
        
        Node* temp = l.first;
        int hd = l.second;
        
        if(m.count(hd)==0){
            m[hd] = temp->data;
        }
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
    for(auto it = m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
}



