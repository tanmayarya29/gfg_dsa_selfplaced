// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        vector<int> ans(N);
        map<int, int> mp;
 
    // indexing for answer = ans array
    int ind = 0;
 
    // initially storing frequency of each element of A1 in
    // map [ key, value ] = [ A1[i] , frequency[ A1[i] ] ]
    for (int i = 0; i < N; i++) {
        mp[A1[i]] += 1;
    }
 
    // traversing each element of A2, first come first serve
    for (int i = 0; i < M; i++) {
 
        // checking if current element of A2 is present in
        // A1 or not if not present go to next iteration
        // else store number of times it is appearing in A1
        // in ans array
        if (mp[A2[i]] != 0) {
 
            // mp[ A2[i] ] = frequency of A2[i] element in
            // A1 array
            for (int j = 1; j <= mp[A2[i]]; j++)
                ans[ind++] = A2[i];
        }
 
        // to avoid duplicate storing of same element of A2
        // in ans array
        mp.erase(A2[i]);
    }
 
    // store the remaining elements of A1 in sorted order in
    // ans array
    for (auto it : mp) {
 
        // it.second = frequency of remaining elements
        for (int j = 1; j <= it.second; j++)
            ans[ind++] = it.first;
    }
    return ans;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends