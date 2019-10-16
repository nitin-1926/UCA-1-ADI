#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node* left, *right;
};
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
 
    return(newnode);
}
 
void mirrorimage(struct node* root)
{
  if (root != NULL)
    {
        struct node* temp;
        mirrorimage(root->left);      
        mirrorimage(root->right);     
 
        temp = root->left;
        root->left  = root->right;   
        root->right = temp;
 
    }
}
 
int heightoftree(struct node* root)
{
    int max;
 
    if (root!=NULL)
    {
        int leftsubtree = heightoftree(root->left);
 
        int rightsubtree = heightoftree(root->right);  
 
 
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
 
void currentlevel(struct node* root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->info);
        }
 
        else if (level > 1)
        {
            currentlevel(root->left, level-1);
            currentlevel(root->right, level-1);
        }
    }
}
 
int main()
{
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
 
    printf("Level Order Traversal of Tree 1 before creating its mirror image is \n");
 
    int i;
    int height = heightoftree(newnode);
 
    for(i = 1; i <= height; i++)      
    {
        currentlevel(newnode,i);
    }
    printf("\n\nLevel Order Traversal of Tree 1 after creating its mirror image is \n");

    height = heightoftree(newnode);
    mirrorimage(newnode);
    for(i = 1; i <= height; i++)   
    {
        currentlevel(newnode,i);
    }
 
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);
 
    printf("\n\nLevel Order Traversal of Tree 2 before creating its mirror image is \n");
 
    height = heightoftree(node);
 
    for(i = 1; i <= height; i++)
    {
        currentlevel(node,i);
    }
 
    printf("\n\nLevel Order Traversal of Tree 2 after creating its mirror image is \n");
 
    height = heightoftree(node);
    mirrorimage(node);
 
    for(i = 1; i <= height; i++)      
    {
        currentlevel(node,i);
    }
    struct node *root = createnode(15);
 
    printf("\n\nLevel Order Traversal of Tree 3 "
               "before creating its mirror image is \n");
    height = heightoftree(root);
    for(i = 1; i <= height; i++)  
    {
        currentlevel(root,i);
    }
    printf("\n\nLevel Order Traversal of Tree 3 after creating its mirror image is \n");
    height = heightoftree(root);
    mirrorimage(root);
    for(i = 1; i <= height; i++)
    {
        currentlevel(root,i);
    }
    return 0;
}