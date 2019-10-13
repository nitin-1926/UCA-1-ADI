#include<stdio.h>
#include<string.h>

#define SIZE 

int Stack[SIZE],top = -1;
int bcount = 0;
int fcount = 0;

void push(int data){
  Stack[++top] = data;
}

int pop(){
  if(top==-1){
    return -1;
  }
  int temp = Stack[top];
  top-=1;
  return temp;
}

int minReversal(char* expr)
{
  int n = strlen(expr);
  if(n%2==1){
    return -1;
  }
  for(int i=0;i<n;i++){
    if(expr[i]=='['){
      push(0);
      ++fcount;
    }
    if(expr[i]==']'){
      int val = pop();
      if(val==-1){
        ++bcount;
      }
      else{
        --fcount;
      }
    }
  }
  if(bcount==0){
    return fcount/2;
  }
  else if(fcount==0){
    return bcount/2;
  }
  else{
    return (fcount+bcount)/2+1;
  }
}
int main(){
	int t;
	scanf("%d",&t);
	while(t!=0){
		int n;
		scanf("%d",&n);
		char str[n+1];
        printf("String should only contain [ or ]")
        scanf("%[^\n]%*c", str);
		int ret = minReversal(str);
		printf("%d\n",ret);
		t--;
	}
	return 0;
}