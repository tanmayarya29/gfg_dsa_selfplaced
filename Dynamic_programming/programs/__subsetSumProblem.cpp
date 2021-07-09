// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n) 
    {
        int sum = 0;
        int i, j;
    
        //storing sum of all elements.
        for (i = 0; i < n; i++) 
        sum += a[i];
    
        //if the total sum is odd, returning false. 
        if (sum % 2 != 0) 
        return false;
    
        //the value of subset[i%2][j] will be true if there exists 
        //a subset of sum j in arr[0, 1, ...., i-1].
        bool subset[2][sum + 1];
    
        for (i = 0; i <= n; i++) 
        {
            for (j = 0; j <= sum; j++) 
            {
                //a subset with sum 0 is always possible.
                if (j == 0) 
                subset[i % 2][j] = true;
    
                //if there exists zero element, no sum is possible.
                else if (i == 0)
                    subset[i % 2][j] = false;
                    
                //else we update the value of subset[i%2][j].
                else if (a[i - 1] <= j)
                    subset[i % 2][j] =
                        subset[(i + 1) % 2][j - a[i - 1]] || subset[(i + 1) % 2][j];
                else
                    subset[i % 2][j] = subset[(i + 1) % 2][j];
            }
        }
        //returning the result.
        return subset[n % 2][sum / 2];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends