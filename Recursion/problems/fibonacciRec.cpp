// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int fibonacci(int n)
{
    if(n==1||n==2) return 1;
    else return (fibonacci(n-1)+fibonacci(n-2));
}

// { Driver Code Starts.\

int main() {
	int T;
	
	//taking total testcases
	scanf("%d", &T);
	while (T--)
	{
	    int n;
	    //taking number n
	    scanf("%d", &n);
	    
	    //calling fibonacci() function
	    printf("%d\n", fibonacci(n));
	    
	    
	}
	return 0;
}  // } Driver Code Ends