#include<stdio.h>

void printTheArray(int arr[], int n){
	for (int i = 0; i < n; i++){ 
		printf("%d ",arr[i]); 
	} 
	printf("\n");
} 

void generateAllBinaryStrings(int n, int arr[], int i){ 
	if (i == n){ 
		printTheArray(arr, n); 
		return; 
	}
	arr[i] = 0; 
	generateAllBinaryStrings(n, arr, i + 1); 
	arr[i] = 1; 
	generateAllBinaryStrings(n, arr, i + 1); 
}
int main(){ 
	int n = 4; 
	int arr[n]; 
	generateAllBinaryStrings(n, arr, 0); 
	return 0; 
} 
