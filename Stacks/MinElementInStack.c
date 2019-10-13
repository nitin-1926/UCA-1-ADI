#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
int STACK[SIZE];
int Min[SIZE];
int top = -1;
int mtop = -1;

int mpeek(){
    return Min[mtop];
}
void mpush(int dd){
    if(mtop>SIZE){
        return;
    }
    mtop++;
    Min[mtop]=dd;
}

void push(int data){
    if(top>SIZE){
        printf("Can't push more\n");
        return;
    }
    if(mtop==-1){
        mpush(data);
    }
    top++;
    STACK[top] = data;
    int min = mpeek();
    if(data<min){
        mpush(data);
    }
}

int pop(){
    if(top<0){
        printf("Can't pop more\n");
        return -1;
    }
    int val = STACK[top--];
    int min = mpeek();
    if(val==min){
        mtop--;
    }
    return val;
}
int getMin(){
    return mpeek();
}
int main(){
    int n;
    scanf("%d",&n);
    if(n>10){
        printf("Sadly Available Size in 10 Only\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        push(num);
    }
    int result = getMin();
    printf("Minimum element in the current STACK is: %d\n",result);
    return 0;
}