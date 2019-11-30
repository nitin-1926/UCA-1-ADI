/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
int total=0;
int L;
void countTotal(struct Node* root){
  if(root == NULL){
    return;
  }
  if(root->left || root->right){
    total++;
  }
  countTotal(root->left);
  countTotal(root->right);
}
int countLeafs(struct Node* root) 
{
	if(root == NULL){
      return 0;
    }
  if(root->left==NULL && root->right==NULL){
    L++;
  }
  int left = countLeafs(root->left);
  int right = countLeafs(root->right);
  return L;
}

int countNonLeafs(struct Node* root) 
{
	if(root == NULL){
      return 0;
    }
  countTotal(root);
  return total-L;
}
