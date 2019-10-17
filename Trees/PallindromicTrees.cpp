#include <iostream> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*) 
		malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 
void inorder(Node* root) 
{ 
	if (root == NULL) 
		return; 

	inorder(root->left); 

	cout << root->data << " "; 

	inorder(root->right); 
} 
int isIdentical(Node* root1, Node* root2) 
{ 
    	if (root1 == NULL && root2 == NULL) 
		return 1; 
	else if (root1 != NULL && root2 == NULL) 
		return 0; 
	else if (root1 == NULL && root2 != NULL) 
		return 0; 
	else {
		if (root1->data == root2->data && isIdentical(root1->left, root2->left) 
			&& isIdentical(root1->right, root2->right)) 
			return 1; 
		else
			return 0; 
	} 
} 

int main() 
{ 
	struct Node* root1 = newNode(5); 
	struct Node* root2 = newNode(5); 
	root1->left = newNode(3); 
	root1->right = newNode(8); 
	root1->left->left = newNode(2); 
	root1->left->right = newNode(4); 

	root2->left = newNode(3); 
	root2->right = newNode(8); 
	root2->left->left = newNode(2); 
	root2->left->right = newNode(4); 

	if (isIdentical(root1, root2)) 
		cout << "Both BSTs are identical"; 
	else
		cout << "BSTs are not identical"; 

	return 0; 
} 
