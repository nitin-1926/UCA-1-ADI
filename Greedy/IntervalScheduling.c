#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Enter the number of Intervals\n");
    int n;
    scanf("%d",&n);
    int start[n];
    int end[n];
    for(int i=0;i<n;i++){
        printf("Enter Start Value of # %d: ",i+1);
        scanf("%d",&start[i]);
        printf("Enter End Value of # %d: ",i+1);
        scanf("%d",&end[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(end[i]>end[j]){
                int temp = end[i];
                end[i] = end[j];
                end[j] = temp;

                int temp2 = start[i];
                start[i] = start[j];
                start[j] = temp2;
            }
        }
    }
    int max = end[0];
    printf("The Maximum Intervals which can be performed are:\n");
    printf("Start Time: %d\n",start[0]);
    printf("End Time: %d\n",end[0]);
    for(int i=0;i<n;i++){
        if(start[i]>=max){
            printf("Next Start Time: %d\n",start[i]);
            printf("Next End Time: %d\n",end[i]);
            max = start[i];
        }
    }
    return 0;
}