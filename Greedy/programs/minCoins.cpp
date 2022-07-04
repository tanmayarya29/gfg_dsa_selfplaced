#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
using namespace std;

/*
applications of greedy:
1. Finding optimal solution:
activity selection
fractional knapsack
job sequensing
prims algo
kruskals algo
dijkstra algo
huffman coding
2. finding close to optimal solution for NP hard problems like travelling salesman solution
*/

int minCoins(int coin[], int n, int amount)
{	
    	sort(coin, coin + n);

    	int res = 0;

    	for(int i = n - 1; i >= 0; i--)
    	{
    		if(coin[i] <= amount)
    		{
    			int c = floor(amount / coin[i]);

    			res = res + c;

    			amount = amount - c * coin[i];
    		}

    		if(amount == 0)
    			break;
    	}

    	return res;
}
    


int main() {
	
      int coin[] = {5, 10, 2, 1}, n = 4, amount = 57;
      
      cout<<minCoins(coin, n, amount);

    
}