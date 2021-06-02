// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        //12-1100 11-1011 ^ = 0111 a^(a-1)
        //1100 & 0011
        //& = 1000
        //| = 1111
        if(n%2!=0)return 1;
        if(n==0)return 0;
        // return floor(log2((n &(~ (n-1))))+1);
        // return floor(log2((n ^ (n-1)))+1);
        return floor(log2((n &(-n)))+1);//-n in binary is ~n-1
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}
  // } Driver Code Ends