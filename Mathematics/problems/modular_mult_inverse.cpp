// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //checking coprimes i.e.gcd=1
    int gcdITER(int a,int b){
    int res=min(a,b);
    while(res>0){
        if(a%res==0 && b%res==0)break;
        res--;
    }
    return res;
    }
    //Complete this function
    int modInverse(int a, int m)//Om for better we hv extended euclidian algo
    {
        //Your code here
        //(b*a)%m=1
        //b has domian 1 to m-1 
        if(gcdITER(a,m)!=1 || m==1){//m==1 coz %1 == 0
            return -1;
        }
        for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends