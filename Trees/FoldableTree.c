/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */
void mirror(struct Node* root){
  if(root==NULL){
    return;
  }
  struct Node* temp;
  mirror(root->left);
  mirror(root->right);
  
  temp = root->left;
  root->left = root->right;
  root->right = temp;
}
int compare(struct Node* a,struct Node* b){
  if(a == NULL && b == NULL){return 1;}
  if(a == NULL || b == NULL){return 0;}
  
  return (compare(a->left,b->right) && compare(a->right,b->left));
}
int isFoldable(struct Node* root)
{
	if(root==NULL){
      return -1;
    }
  mirror(root->left);
  int res = compare(root->left, root->right);
  return res;
}
