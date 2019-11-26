/* struct Node
{
    int data;	// For data
    int p;		// For priority
    struct Node* next;	// For link
};*/

void enqueue(struct Node** head, int data, int priority)
{
	struct Node *ptr, *temp;
  ptr = *head;
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->p = priority;
  node->next = NULL;
  if(*head == NULL){
    *head = node;
  }
  else if(((*head)->p)>priority){
    node->next = *head;
    *head = node;
  }
  else{
    ptr = *head;
    while(((ptr->next) != NULL) && (((ptr->next)->p) <= priority))
      ptr = ptr->next;
    node->next = ptr->next;
    ptr->next = node;
  }
}

int dequeue(struct Node** head)
{
	if(*head != NULL)
    {
        int res = (*head)->data;
        (*head) = (*head)->next;
      return res;
    }
    else
        return -1;
}