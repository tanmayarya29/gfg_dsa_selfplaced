// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
    public:
    static bool sortByVal(const pair<int, int>& a,
                      const pair<int, int>& b)
{
 
   // If frequency is same then sort by index
   if (a.second == b.second) 
       return a.first < b.first;
 
   return a.second > b.second;
}
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int a[],int n)
    {
        //Your code here
        vector<int>res;
 
   unordered_map<int, int> m;
 
   vector<pair<int, int> > v;
 
   for (int i = 0; i < n; ++i) {
 
       // Map m is used to keep track of count 
       // of elements in array
       m[a[i]]++;     
   }
 
   // Copy map to vector
   copy(m.begin(), m.end(), back_inserter(v));
 
   // Sort the element of array by frequency
   sort(v.begin(), v.end(), sortByVal);
 
   for (int i = 0; i < v.size(); ++i) 
      while(v[i].second--)
      {
              res.push_back(v[i].first);
      }
 
   return res;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends