// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *a, int n){
        //code here
        if (n == 0)
        return {0, 0};
 
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int m = (s + e) / 2;
 
        // if a[m] = m + a[0], there is no
        // repeating character in [s..m]
        if (a[m] >= m + a[0])
            s = m + 1;
 
       // if a[m] < m + a[0], there is a
       // repeating character in [s..m]
        else
            e = m;
    }
    return {a[s], n - (a[n - 1] - a[0])};
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<int, int> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}  // } Driver Code Ends