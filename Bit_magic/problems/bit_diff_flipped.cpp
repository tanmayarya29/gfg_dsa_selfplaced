// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countSetBitLookUpTable(int n){//***time=o(255)for 32 bit
    int table[256];
    //initialise
    table[0]=0;
    for(int i=1;i<=255;i++){
        table[i]=(i&1)+table[(i/2)];
    }
    //count
    int res=table[n&0xff];
    n>>=8;
    res+=table[n&0xff];
    n>>=8;
    res+=table[n&0xff];
    n>>=8;
    return res;
        
    }
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        return countSetBitLookUpTable(a^b);
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends