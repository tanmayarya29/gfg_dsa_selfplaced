#include <iostream>
#include <limits.h>
using namespace std;

int countBSTs(int n)//n^2 time n space
{
	int dp[n+1];

	dp[0] = 1;

	for(int i=1; i<=n; i++)
	{
		dp[i] = 0;

		for(int j=0; j<i; j++)
		{
			dp[i] += dp[j] * dp[i-j-1];
		}
	}

	return dp[n];
}

//efficient = catalans num = 1/(n+1)*2nCn = 1/(n+1)*(2n)!/(n!*(n+1)!)

int main() {
    
    	int n = 4;

    	cout<<countBSTs(n);
    	
    	return 0;
}