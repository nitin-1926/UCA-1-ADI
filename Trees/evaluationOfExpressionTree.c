/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

int evaluateTree(struct Node* t1)
{
	if(t1 == NULL){
      return 0;
    }
  int a = evaluateTree(t1->left);
  int b = evaluateTree(t1->right);
  
  if(t1->data == 42){
    if(t1->left || t1->right)
      return a*b;
    else
      return 42;
  }
  if(t1->data == 43){
    if(t1->left || t1->right)
      return a+b;
    else
      return 43;
  }
  if(t1->data == 45){
    if(t1->left || t1->right)
    	return a-b;
    else
      return 45;
  }
  if(t1->data == 47){
    if(t1->left || t1->right)
      return a/b;
    else
      return 47;
  }
}
