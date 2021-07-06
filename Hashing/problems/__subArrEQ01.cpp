// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        // 'um' implemented as hash table to store
    // frequency of values obtained through
    // cumulative sum
    unordered_map<long long, long long> um;
    long long curr_sum = 0;
 
    // Traverse original array and compute cumulative
    // sum and increase count by 1 for this sum
    // in 'um'. Adds '-1' when arr[i] == 0
    for (long long i = 0; i < n; i++) {
        curr_sum += (arr[i] == 0) ? -1 : arr[i];
        um[curr_sum]++;
    }
 
    long long count = 0;
    // traverse the hash table 'um'
    for (auto itr = um.begin(); itr != um.end(); itr++) {
 
        // If there are more than one prefix subarrays
        // with a particular sum
        if (itr->second > 1)
            count += ((itr->second * (itr->second - 1)) / 2);
    }
 
    // add the subarrays starting from 1st element and
    // have equal number of 1's and 0's
    if (um.find(0) != um.end())
        count += um[0];
 
    // required count of subarrays
    return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends