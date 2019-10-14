#include <stdio.h>
#define SIZE 10
int front=-1, rear=-1;
int array[SIZE];

void enqueue(int item)
{
  if (rear == SIZE)
    return;
  if(front == -1 && rear == -1){
    front++;
    rear++;
  }
  else
    rear++;
  array[rear] = item;
  printf("%d enqueued to queue.\n",item);
}
int dequeue()
{
  if (front > rear)
  {
    printf("Queue is Empty.\n");
    return -1;
  }
  int item = array[front];
  front++;
  printf("%d dequeued from queue.\n",item);
  return item;
}

int main()
{
  printf("Front = %d, Rear = %d\n",front,rear);
  enqueue(10);
  printf("Front = %d, Rear = %d\n",front,rear);
  enqueue(20);
  printf("Front = %d, Rear = %d\n",front,rear);
  enqueue(30);
  printf("Front = %d, Rear = %d\n",front,rear);
  enqueue(40);
  printf("Front = %d, Rear = %d\n",front,rear);

  dequeue();
  printf("Front = %d, Rear = %d\n",front,rear);
  dequeue();
  printf("Front = %d, Rear = %d\n",front,rear);
  dequeue();
  printf("Front = %d, Rear = %d\n",front,rear);
  dequeue();
  printf("Front = %d, Rear = %d\n",front,rear);
  dequeue();
  printf("Front = %d, Rear = %d\n",front,rear);

  enqueue(50);
  printf("Front = %d, Rear = %d\n",front,rear);
}
