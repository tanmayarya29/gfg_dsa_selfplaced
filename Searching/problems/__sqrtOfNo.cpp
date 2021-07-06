// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
    // Your code goes here 
     // Base cases
    if (x == 0 || x == 1)
        return x;
 
    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = x, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
 
        // If x is a perfect square
        if (mid * mid == x)
            return mid;
 
        // Since we need floor, we update answer when
        // mid*mid is smaller than x, and move closer to
        // sqrt(x)
 
        /*
           if(mid*mid<=x)
                   {
                           start = mid+1;
                           ans = mid;
                   }
            Here basically if we multiply mid with itself so
           there will be integer overflow which will throw
           tle for larger input so to overcome this
           situation we can use long or we can just divide
            the number by mid which is same as checking
           mid*mid < x
 
           */
        if (mid <= x / mid) {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            end = mid - 1;
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends