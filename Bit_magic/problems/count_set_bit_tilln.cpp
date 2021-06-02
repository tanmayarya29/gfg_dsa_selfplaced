// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int N)
    {
        // Your logic here
        int two = 2,ans = 0;
        int n = N;
        while(n){
            ans += (N/two)*(two>>1);
            if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1;
            two <<= 1;
            n >>= 1;
        }
    return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends