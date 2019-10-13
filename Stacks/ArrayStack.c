#include<stdio.h>
#define SIZE 20
int Stack[SIZE], top=-1;

int isFull(){
  return top==(SIZE-1);
}

int isEmpty(){
  return top==-1;
}

int push(int item){
  if (isFull()){
    return -1;
  }
  Stack[++top] = item;
}

int pop(){
  int temp;
  if (isEmpty()){
    return -1;
  }
  temp=Stack[top--];

  return temp;
}

int main(){
  int temp;
  push(56);
  push(544);
  temp=pop();
  printf("%d\n",temp);
  push(8);
  temp=pop();
  printf("%d\n",temp);
  temp=pop();
  printf("%d\n",temp);
  temp=pop();
  printf("%d\n",temp);
  return 0;
}
