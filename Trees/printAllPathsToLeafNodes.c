/* struct Node{int data;struct Node *left,*right;};*/
int count = 0;
void printArray(int paths[], int pathlen){
  count++;
  for(int i=0;i<pathlen;i++){
    printf("%d ",paths[i]);
  }
  printf("%d",pathlen-1);
}
void pathsRecur(struct Node* root, int paths[], int pathlen){
  if(root == NULL){
    return;
  }
  paths[pathlen] = root->data;
  pathlen++;
  
  if(root->left == NULL && root->right == NULL){
    printArray(paths,pathlen);
    printf("\n");
  }
  else{
    pathsRecur(root->left,paths,pathlen);
    pathsRecur(root->right,paths,pathlen);
  }
}
void printAllPaths(struct Node* root) 
{
  if(root == NULL){
    return;
  }
	int paths[999];
  pathsRecur(root, paths, 0);
  printf("%d",count);
}
