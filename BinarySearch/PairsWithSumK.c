#include<stdio.h>
int countpair(int ar[],int s,int e,int sum){
    int c=0;
    while(s<e){
        int total=ar[s]+ar[e];
        if(total==sum){
           if(ar[s]==ar[s+1]){
               int temp=0;
               while(temp<e){
                   if(ar[temp]+ar[e]==sum)
                    c++;
                   temp++;
               }
               e--;
           }
           else{
            c++;
             s++;
           }
        }
        else if(total<sum)
            s++;
        else
            e--;
    }
    return c;
}
int main(){
    printf("Enter the number of elements");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int sum;
    printf("Enter the sum you want to check");
    scanf("%d",&sum);
    printf("\nNumber of pairs with the given sum are: %d\n",countpair(ar,0,n-1,sum));
}