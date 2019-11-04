#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node{
        public:
                int data;
                Node* next[2];
                Node(int data){
                        this->data=data;
                        next[0]=NULL;
                        next[1]=NULL;
                }
};
Node* construct_binary(Node* root,int arr[],int start,int end){
        if(start>end)
                return NULL;
                root=new Node(arr[start]);
                if(2*start+1<end && arr[2*start+1]!=-1)
                        root->next[0]=construct_binary(root->next[0],arr,2*start+1,end);
                if(2*start+2<end && arr[2*start+2]!=-1)
                        root->next[1]=construct_binary(root->next[1],arr,2*start+2,end);
                return root;
}
void print_level(Node* root){
        if(root==NULL)
                return;

        queue<Node*>q;
        Node* temp;
        q.push(root);
        q.push(NULL);
        int count=1;
        stack <int> stk;
        stk.push(-100);
        while(q.size()>1){
              if(count%2!=0 && q.front()!=NULL){
                        while(q.front()!=NULL){
                                temp=q.front();
                                if(temp->next[0])
                                        q.push(temp->next[0]);
                                if(temp->next[1])
                                        q.push(temp->next[1]);
                                cout<<temp->data;
                                q.pop();
                                if(q.front()!=NULL){cout<<" ";}
                        }
                }

                if(q.front()==NULL){
                        count++;
                        q.pop();
                        if(q.front()!=NULL){
                            cout<<" ";
                        }
                        q.push(NULL);
                }

                if(count%2==0 && q.front()!=NULL){
                        while(q.front()!=NULL){
                                temp=q.front();
                                if(temp->next[0])
                                        q.push(temp->next[0]);
                                if(temp->next[1])
                                        q.push(temp->next[1]);
                                stk.push(q.front()->data);
                                q.pop();
                        }
                        while(stk.empty()==false){
                                cout<<stk.top();
                            stk.pop();
                            if(stk.top()!=-100){cout<<" ";
                            }
                            else{break;}
                        }
                }
        }
}
int main(){
        int arr[]={1,2,3,4,5,6,7};
        int k=0;
        Node* root=construct_binary(root,arr,0,6);
        print_level(root);
        return 0;
}
