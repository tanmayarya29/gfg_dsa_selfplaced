// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int x)
    {
    	// Your code here
    	// Get all even bits of x 0xAAAAAAAA-has all even bits as 1
        unsigned int eb = x & 0xAAAAAAAA;
     
        // Get all odd bits of x 0x55555555-has all odd bits as 1
        unsigned int ob = x & 0x55555555;
     
        eb >>= 1; // Right shift even bits
        ob <<= 1; // Left shift odd bits
     
        return (eb|ob);
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends