#include <stdio.h>
#include <stdlib.h>

struct StackLL{
  int data;
  struct StackLL* next;
};

struct StackLL* newElement(int data){
  struct StackLL* StackLL = (struct StackLL*) malloc(sizeof(struct StackLL));
  if(!StackLL){
    printf("OVERFLOW \n");
  }
  StackLL->data = data;
  StackLL->next = NULL;
  return StackLL;
}

int isEmpty(struct StackLL *root){
  return !root;
}

int push(struct StackLL** root, int data){
  struct StackLL* StackLL = newElement(data);
  StackLL->next = *root;
  *root = StackLL;
  printf("%d pushed to stack\n",data);
  return 1;
}

int pop(struct StackLL** root){
  if (isEmpty(*root)){
    printf("UNDERFLOW");
    return -1;
  }
  struct StackLL* temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);
  printf("%d popped from stack\n", popped);
  return popped;
}

int main(){
  struct StackLL* main_Stack = NULL;
  int temp;
  push(&main_Stack, 12);
  push(&main_Stack, 23);

  pop(&main_Stack);

  push(&main_Stack, 54);

  pop(&main_Stack);
  pop(&main_Stack);
  pop(&main_Stack);
  return 0;
}
