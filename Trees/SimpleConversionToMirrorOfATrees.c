void findMirror(struct Node* root)
{
	if(root==NULL){
      return;
    }
  struct Node* head = NULL;
  
  findMirror(root->left);
  findMirror(root->right);
  
  head = root->left;
  root->left = root->right;
  root->right = head;
}
