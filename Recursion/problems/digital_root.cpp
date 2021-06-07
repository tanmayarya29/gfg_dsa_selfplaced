// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C
int sumOfDigits(int n)
    {
        //Your code here
        if(n<1)return 0;
        return n%10+sumOfDigits(n/10);
    }

int digitalRoot(int n)
{
    
    //Your code here
    if(n<10)return n;
    int sod=sumOfDigits(n);
    if(sod%9==0) return 9;
    else return (sod%9);
}

// { Driver Code Starts.


int main() {
	int T;
	scanf("%d", &T);//taking testcases
	while(T--)
	{
	    int n;
	    scanf("%d", &n);//taking number n
	    
	    //calling digitalRoot() function
	    printf("%d\n", digitalRoot(n));
	    
	    
	}
	return 0;
}  // } Driver Code Ends