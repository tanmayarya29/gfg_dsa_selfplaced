// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
        
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        
        // Your code here
        int lmin[n],rmax[n];
        lmin[0]=arr[0];
        rmax[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++){
            lmin[i]=min(lmin[i-1],arr[i]);
        }
        for(int i=n-2;i<=0;i++){
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        int i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n) {
        if (lmin[i] < rmax[j]) {
            maxDiff = max(maxDiff, j - i);
            j = j + 1;
        }
        else
            i = i + 1;
    }
 
    return maxDiff+1;
        
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends