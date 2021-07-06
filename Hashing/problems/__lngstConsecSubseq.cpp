// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++) {
       
        // adding element from
        // array to PriorityQueue
        pq.push(arr[i]);
    }
 
    // Storing the first element
    // of the Priority Queue
    // This first element is also
    // the smallest element
    int prev = pq.top();
    pq.pop();
 
    // Taking a counter variable with value 1
    int c = 1;
 
    // Storing value of max as 1
    // as there will always be
    // one element
    int max = 1;
    while (!pq.empty()) {
       
        // check if current peek
        // element minus previous
        // element is greater then
        // 1 This is done because
        // if it's greater than 1
        // then the sequence
        // doesn't start or is broken here
        if (pq.top() - prev > 1) {
           
            // Store the value of counter to 1
            // As new sequence may begin
            c = 1;
 
            // Update the previous position with the
            // current peek And remove it
            prev = pq.top();
            pq.pop();
        }
 
        // Check if the previous
        //  element and peek are same
        else if (pq.top() - prev == 0) {
           
            // Update the previous position with the
            // current peek And remove it
            prev = pq.top();
            pq.pop();
        }
       
        // If the difference
        // between previous element and peek is 1
        else {
           
            // Update the counter
            // These are consecutive elements
            c++;
 
            // Update the previous position
            //  with the current peek And remove it
            prev = pq.top();
            pq.pop();
        }
       
        // Check if current longest
        // subsequence is the greatest
        if (max < c) {
           
            // Store the current subsequence count as
            // max
            max = c;
        }
    }
    return max;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends