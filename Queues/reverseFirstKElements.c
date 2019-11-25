/*
int front=-1, rear=-1;
int array[SIZE];
void enqueue(int item);
int dequeue();

Above variables are used for queue, SIZE, front and rear and all are global variables. Complete the below two methods. */
int stack[SIZE];
int top = -1;
void push(int data){
  stack[++top] = data;
}
int pop(){
  int temp = stack[top];
  top--;
  return temp;
}
int peek(){
  return stack[top];
}

void reverseKelementsQueue (int q[], int K)
{
    int ss = rear+1;
  for(int i=0;i<K;i++){
    int num = dequeue(q);
    push(num);
  }
  int stop = peek();
  while(top>=0){
    int lol = pop();
    enqueue(lol);
  }
  for(int i=0;i<ss-K;i++){
    int data = dequeue(q);
    enqueue(data);
  }
}