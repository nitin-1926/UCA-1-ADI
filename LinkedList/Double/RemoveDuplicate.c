struct Node* removeDupsDLL(struct Node* head)
{
	if(head==NULL){
      return NULL;
    }
  int flag=0;
  	struct Node* ptr = head->next;
  struct Node* init = head;
  while(ptr){
    init = head;
    flag = 0;
    while(init != ptr){
      if(init->data == ptr->data){
        flag=1;
        break;
      }
      init = init->next;
    }
      if(flag==1){
        init->next = ptr->next;
        ptr->prev = init;
      }
    ptr = ptr->next;
  }
  return head;
}