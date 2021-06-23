// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int normalMaxSum(int arr[],int n){
    int maxEnding=arr[0],res=arr[0];
   for(int i=1;i<n;i++){
       maxEnding=max(maxEnding+arr[i],arr[i]);
       res=max(res,maxEnding);
   }
   return res;
}

int circularSubarraySum(int arr[],int n){//efficient//n
//normal sum
    int maxNormal=normalMaxSum(arr,n);
    if(maxNormal<0)return maxNormal;
//circular sum
    int arr_sum=0;
    for(int i=0;i<n;i++){
        arr_sum+=arr[i];
        arr[i]=-arr[i];
    }
    int max_circular=arr_sum+normalMaxSum(arr,n);
    return max(maxNormal,max_circular);
}
    
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends