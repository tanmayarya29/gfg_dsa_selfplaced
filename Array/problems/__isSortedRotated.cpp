// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    //Function to check if array is sorted in increasing order and rotated.
    bool II (int arr[], int n)
    {
    	int i = 0;
    	//We use a loop to check whether elements are in increasing order and 
    	//stop at position where we find a smaller number than previous one.
    	while (i < n - 1 and arr[i] <= arr[i + 1]) i++;
    	
    	//If we reach the end of the array, we return false.
    	if (i == n - 1) return false;
    
    	i++;
    	//Now we check whether all remaining elements are in increasing order.
    	while (i < n - 1 and arr[i] <= arr[i + 1]) i++;
    	
    	//If we reach the end and the last element is smaller than or equal to
        //first element we return true else we return false.
    	if (i == n - 1 and arr[n - 1] <= arr[0])
    		return true;
    	else
    		return false;
    }
    
    //Function to check if array is sorted in decreasing order and rotated.
    bool DD (int arr[], int n)
    {
    	int i = 0;
    	//We use a loop to check whether elements are in decreasing order and 
    	//stop at position where we find a smaller number than next one.
    	while (i < n - 1 and arr[i] >= arr[i + 1]) i++;
    	
    	//If we reach the end of the array, we return false.
    	if (i == n - 1) return false;
    
    	i++;
    	//Now we check whether all remaining elements are in decreasing order.
    	while (i < n - 1 and arr[i] >= arr[i + 1]) i++;
    	
    	//If we reach the end and the last element is larger than or equal to 
        //first element we return true else we return false.
    	if (i == n - 1 and arr[n - 1] >= arr[0])
    		return true;
    	else
    		return false;
    }
    
    //Function to check if array is sorted and rotated.
    bool checkRotatedAndSorted(int arr[], int num) {
        //returning true if any of the two function gives true.
    	return (II (arr, num) || DD (arr, num));
    }
        
};

// { Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        Solution ob;
        
        //function call
        flag = ob.checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends