/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node.
*/
int front = -1, rear = -1;
#define SIZE 100
struct Node* q[SIZE];
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
struct Node* peekNext(){
  return q[front];
}
int findRightSibling(struct Node* root,int key)
{
	if(root==NULL){
      return -1;
    }
  enqueue(root);
  enqueue(NULL);
  while(front<rear){
    struct Node* ptr = dequeue();
    if(ptr==NULL){
      enqueue(NULL);
    }
    else{
      if(ptr->data == key){
        struct Node* lol = peekNext();
        if(lol == NULL){
          return -1;
        }
        else{
          return lol->data;
        }
      }
      if(ptr->left != NULL){
        enqueue(ptr->left);
      }
      if(ptr->right != NULL){
        enqueue(ptr->right);
      }
    }
  }
}
