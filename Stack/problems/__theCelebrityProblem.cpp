
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        for (int i = 0; i < n; i++)
            s.push(i);
        while (s.size() >= 2) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (M[a][b] == 0)
                s.push(a);
            else
                s.push(b);
        }
        int ans = s.top();
        for (int i = 0; i < n; i++) {
            if (i != ans){
                if (M[i][ans] == 0 || M[ans][i] == 1)
                    return -1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends