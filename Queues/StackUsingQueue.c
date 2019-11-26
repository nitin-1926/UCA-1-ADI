/*
int top = -1;
int front1=-1, rear1=-1;
int front2=-1, rear2=-1;
int q1[SIZE], q2[SIZE];

void enqueue(int q[], int *f, int *r, int item);
int dequeue(int q[], int *f, int *r);

Above two queue and their enqueue and dequeue functions are available, 
So complete the below two methods to implement stack using these functions. */

void reverse(){
  if(front1 >= rear1){
    return;
  }
  int data = dequeue(q1,&front1,&rear1);
    reverse();
  enqueue(q1,&front1,&rear1,data);
}
int push(int item)
{
	enqueue(q1,&front1,&rear1,item);
}
int pop()
{
  if(front1>rear1){
    return -1;
  }
  reverse();
	int res = dequeue(q1,&front1,&rear1);
  reverse();
  return res;
}