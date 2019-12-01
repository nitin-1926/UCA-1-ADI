/* struct Node{int data;struct Node *left, *right;};The above structure is used for tree node. */

int areSameTree(struct Node* t1, struct Node* t2){
	if(t1 == NULL && t2== NULL){
      return 1;
    }
  else if(t1 != NULL && t2!= NULL){
    return (
    	t1->data == t2->data && areSameTree(t1->left,t2->left) && areSameTree(t1->right,t2->right)
    );
  }
  else
  	return 0;
}

