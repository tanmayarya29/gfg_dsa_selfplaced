// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
   public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n)
    {
        //base cases
        if(n<=1)            
            return 0;
        if(arr[0] == 0)    
            return -1;
        
        //using maxrange to store the index till which we can jump and 
        //steps to store the number of indexes we can travel in one jump.  
        int maxrange = arr[0]; 
        int steps = arr[0];   
        int jumps = 1;    
        
        for(int i = 1; i<n; ++i)
        {
            //if we reach the end of array, we return the number of jumps.
            if(i == n-1) 
            return jumps; 
            
            //updating maxrange by comparing current maxrange and current value.
            maxrange = max(maxrange, i+arr[i]);
            //reducing steps each time we are moving forward.
            steps--;                            
            
            //if steps become 0, we have to increase the number of jumps.
            if(steps == 0)
            {                     
                ++jumps;  
                
                //if maxrange is less than or equal to i, we can't
                //move further so we return -1.
                if(i>= maxrange) 
                return -1;    
                
                //updating the steps.
                steps = maxrange - i;   
            }
         }
         return -1; 
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}  // } Driver Code Ends