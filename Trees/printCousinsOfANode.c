/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node.
*/
int front = -1, rear = -1, top=-1;
#define SIZE 100
struct Node* q[SIZE];
struct Node* s[SIZE];
void push(struct Node* item){
  s[++top] = item;
}
struct Node* pop(){
  if(top<0){
    return NULL;
  }
  else{
    return s[top--];
  }
}
void enqueue(struct Node* item){
  if(front==-1 && rear==-1){
    front++;
    rear++;
    q[rear] =  item;
  }
  else{
    rear++;
    q[rear] = item;
  }
}
struct Node* dequeue(){
  if(front>rear || front==-1){
    return NULL; 
  }
  struct Node* res = q[front++];
  return res;
}
void printCousins(struct Node* root,int key)
{
	if(root==NULL){
      printf("-1");
      return;
    }
  struct Node* temp = root;
  int none = 0;
  int flag = 0;
  enqueue(root);
  enqueue(NULL);
  while(front<rear){
    struct Node* node = dequeue();
    if(node!=NULL && node->data == key){
      struct Node* ptr = pop();
      while(ptr!=NULL){
        ptr = pop();
      }
      ptr = pop();
      if(ptr == temp){printf("-1");none=1;}
      else{
        while(ptr!=NULL){
          flag=0;
          if(ptr->left){if(ptr->left->data == key){flag=1;}}
          if(ptr->right){if(ptr->right->data == key){flag=1;}}
          if(flag==0){
            if(ptr->left){printf("%d ",ptr->left->data);none=1;}
            if(ptr->right){printf("%d ",ptr->right->data);none=1;}
          }
          ptr=pop();
        }
        if(none == 0){
          printf("-1");
        }
      }
    }
    else{
      if(node==NULL){
        enqueue(NULL);
        push(NULL);
      }
      else{
        push(node);
        if(node->left != NULL){
          enqueue(node->left);
        }
        if(node->right != NULL){
          enqueue(node->right);
        }
      }
    }
  }
}