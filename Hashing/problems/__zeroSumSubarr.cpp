// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ,int sum=0) {
        //code here
        // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    unordered_map<ll, ll> prevSum;
 
    ll res = 0;
 
    // Sum of elements so far.
    ll currsum = 0;
 
    for (ll i = 0; i < n; i++) {
 
        // Add current element to sum so far.
        currsum += arr[i];
 
        // If currsum is equal to desired sum,
        // then a new subarray is found. So
        // increase count of subarrays.
        if (currsum == sum)
            res++;
 
        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
 
        // Add currsum value to count of
        // different values of sum.
        prevSum[currsum]++;
    }
 
    return res;
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
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends