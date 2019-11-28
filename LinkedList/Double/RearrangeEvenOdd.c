/* struct Node{int data;struct Node *next;struct Node *prev;};*/
struct Node* rearrangeList(struct Node* head)
{
  if(head==NULL){
    return NULL;
  }
  struct Node* odd = NULL, *oddTail = NULL;
	struct Node* even = NULL, *evenTail = NULL;

	struct Node* curr = head;
  int size = 0;

	while (curr != NULL)
	{
      size++;
		if (size %2==1 ) // current node is odd
		{
			// handle head for first odd node
			if (odd == NULL)
				odd = oddTail = curr;
			else 
			{
				oddTail->next = curr;
				oddTail = oddTail->next;
			}
		}
		else // current node is even
		{
			// handle head for first even node
			if (even == NULL)
				even = evenTail = curr;
			else 
			{
				evenTail->next = curr;
				evenTail = curr;
			}
		}
		curr = curr->next;
	}

	// if list contains at-least one even node
	if (even) 
	{
		head = even;
		evenTail->next = odd;
	}
	// special case - list contains all odd nodes
	else
		head = odd;

	// NULL to terminate the list, else it will go in infinite loop
	if (oddTail)
		oddTail->next = NULL;
  return head;
}