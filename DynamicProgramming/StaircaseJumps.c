#include <stdio.h> 

int countWays(int n) 
{ 
	int res[n + 1]; 
	res[0] = 1; 
	res[1] = 1; 
	res[2] = 2; 
	for (int i = 3; i <= n; i++) 
		res[i] = res[i-1] + res[i-2] + res[i-3]; 
	return res[n]; 
} 

int main() 
{ 
	int n = 4; 
	printf("%d", countWays(n)); 
	return 0; 
} 
