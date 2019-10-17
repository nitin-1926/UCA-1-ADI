#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
int tree[20] = {0};

// void setRight(int *,int, int);

// void setLeft(int a[],int val,int i){
//   if(a[i]!=0){
//     a[i]=val;
//   }
//   else{
//     if(val<a[i]){
//       setLeft(a,val,i*2+1);
//     }
//     else{
//      setRight(a,val,i*2+2);
//     }
//   }
// }
// void setRight(int a[],int val,int i){
//   if(a[i]!=0){
//     a[i]=val;
//   }
//   else{
//     if(val<a[i]){
//       setLeft(a,val,i*2+1);
//     }
//     else{
//      setRight(a,val,i*2+2);
//     }
//   }
  
// }

void printTree(int a[]){
  int i =0;
  while(i<SIZE){
    if(a[i]!=0)
      printf("%d ",a[i]);
    else
      printf("- ");
    i++;
  }
  printf("\n");
}

void setInTree(int a[], int val, int i){
  if(a[i]==0){
    a[i]=val;
  }
  else{
    if(val<a[i]){
      setInTree(a,val,i*2+1);
    }
    else{
     setInTree(a,val,i*2+2);
    }
  }

}

int main(){

  setInTree(tree,1,0);
  setInTree(tree,2,0);
  setInTree(tree,3,0);
  // setInTree(tree,2,0);
  // setInTree(tree,6,0);

  printTree(tree);

  return 0;
}