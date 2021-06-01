// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isPrimeO(int num){//O(sqrtn)
    if(num==1||(num!=2&&num%2==0)||(num!=3&&num%3==0))return false;
    for(auto i=5;i<=sqrt(num);i+=6){
        if(num%i==0||num%(i+2)==0){
            return false;
        }
    }
    return true;
}
    int exactly3Divisors(int n)
    {
        if(n<4)return 0;
        int count=0;
        for(int i=2;i*i<=n;i++){
            if(isPrimeO(i)){
                count++;
            }
        }
        return count;
}
    
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends