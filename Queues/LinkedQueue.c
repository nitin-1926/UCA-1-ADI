#include <stdio.h>
#include <stdlib.h>

struct QNode
{
  int data;
  struct QNode *next;
};

struct QueueLL
{
  struct QNode *front,*rear;
};

struct QNode* newElement(int data)
{
  struct QNode *temp = (struct QNode*) malloc(sizeof(struct QNode));
  if(!temp){
    printf("OVERFLOW \n");
  }
  temp->data = data;
  temp->next = NULL;
  return temp;
}

int EnQueue(struct QueueLL* root, int data)
{
  struct QNode *temp = newElement(data);
  if (root->rear == NULL)
  {
    root->front = root->rear = temp;
    printf("%d EnQueueed to Queue\n",data);
    printf("Front = %d, Rear = %d\n",root->front->data, root->rear->data);
    return 1;
  }
  root->rear->next = temp;
  root->rear = temp;
  printf("%d EnQueueed to Queue\n",data);
  printf("Front = %d, Rear = %d\n",root->front->data, root->rear->data);
  return 1;
}

int DeQueue(struct QueueLL* root)
{
  if (root->front == NULL){
    printf("UNDERFLOW");
    return -1;
  }
  int temp = root->front->data;
  root->front = root->front->next;
  if (root->front == NULL)
    root->rear = NULL;
  printf("%d DeQueueped from Queue\n", temp);
  if(root->front != NULL && root->rear != NULL)
    printf("Front = %d, Rear = %d\n",root->front->data, root->rear->data);
  return temp;
}

int main()
{
  struct QueueLL *main_Queue = (struct QueueLL*)malloc(sizeof(struct QueueLL));
  main_Queue->front = main_Queue->rear = NULL;
  EnQueue(main_Queue, 12);
  EnQueue(main_Queue, 23);
  DeQueue(main_Queue);
  EnQueue(main_Queue, 54);
  DeQueue(main_Queue);
  DeQueue(main_Queue);
  DeQueue(main_Queue);
  return 0;
}
