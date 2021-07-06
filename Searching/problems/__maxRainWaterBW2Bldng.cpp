// { Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    { 
        //Your code here
        // To store the maximum water so far
    int maximum = 0;
 
    // Both the pointers are pointing at the first
    // and the last buildings respectively
    int i = 0, j = n - 1;
 
    // While the water can be stored between
    // the currently chosen buildings
    while (i < j)
    {
 
        // Update maximum water so far and increment i
        if (height[i] < height[j])
        {
            maximum = max(maximum, (j - i - 1) * height[i]);
            i++;
        }
 
        // Update maximum water so far and decrement j
        else if (height[j] < height[i])
        {
            maximum = max(maximum, (j - i - 1) * height[j]);
            j--;
        }
 
        // Any of the pointers can be updated (or both)
        else
        {
            maximum = max(maximum, (j - i - 1) * height[i]);
            i++;
            j--;
        }
    }
 
    return maximum;
    } 
};



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends