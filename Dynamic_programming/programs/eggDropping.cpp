#include <bits/stdc++.h> 
using namespace std; 
//recursive solution
// A utility function to get 
// maximum of two integers 
int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 

// Function to get minimum 
// number of trials needed in worst 
// case with n eggs and k floors 
int eggDrop(int n, int k) 
{ 
	// If there are no floors, 
	// then no trials needed. 
	// OR if there is one floor, 
	// one trial needed. 
	if (k == 1 || k == 0) 
		return k; 

	// We need k trials for one 
	// egg and k floors 
	if (n == 1) 
		return k; 

	int min = INT_MAX, x, res; 

	// Consider all droppings from 
	// 1st floor to kth floor and 
	// return the minimum of these 
	// values plus 1. 
	for (x = 1; x <= k; x++) { 
		res = max( 
			eggDrop(n - 1, x - 1), 
			eggDrop(n, k - x)); 
		if (res < min) 
			min = res; 
	} 

	return min + 1; 
} 

//dp solution//f^2*e time complexity fe space
int eggDropdp(int e, int f) 
{ 
    int dp[f+1][e+1];
    
    for(int i = 1; i <= e ;i++){
        dp[1][i] = 1;
        dp[0][i] = 0;
    }
    
    for(int j = 1; j <= f; j++){
        dp[j][1] = j;
    }
    
    for(int i = 2; i <= f; i++){
        for(int j = 2; j <= e; j++){
            dp[i][j] =INT_MAX;
            for(int x = 1; x <= i; x++){
                dp[i][j] = min(dp[i][j], 1 + max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    
    return dp[f][e];
    
}

int main() 
{ 
	int n = 2, k = 10; 
	cout<< eggDrop(n, k) << endl; 
    cout<< eggDropdp(n, k) << endl;
	return 0; 
} 


