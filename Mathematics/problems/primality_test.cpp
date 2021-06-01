// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        bool isPrime(int num)
    {
       if(num==1||(num!=2&&num%2==0)||(num!=3&&num%3==0))return false;
    for(auto i=5;i<=sqrt(num);i+=6){
        if(num%i==0||num%(i+2)==0){
            return false;
        }
    }
    return true;
    }

};

// { Driver Code Starts.

int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n
        Solution ob;
        if(ob.isPrime(N)) 
            cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends