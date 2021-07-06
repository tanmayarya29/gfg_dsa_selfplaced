// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        // Initialize the sumRow[] and sumCol[]
    // array to 0
    int sumRow[n], sumCol[n];
    memset(sumRow, 0, sizeof(sumRow));
    memset(sumCol, 0, sizeof(sumCol));
 
    // Calculate sumRow[] and sumCol[] array
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            sumRow[i] += matrix[i][j];
            sumCol[j] += matrix[i][j];
        }
 
    // Find maximum sum value in either
    // row or in column
    int maxSum = 0;
    for (int i = 0; i < n; ++i) {
        maxSum = max(maxSum, sumRow[i]);
        maxSum = max(maxSum, sumCol[i]);
    }
 
    int count = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
 
        // Find minimum increment required in
        // either row or column
        int diff = min(maxSum - sumRow[i],
                       maxSum - sumCol[j]);
 
        // Add difference in corresponding cell,
        // sumRow[] and sumCol[] array
        matrix[i][j] += diff;
        sumRow[i] += diff;
        sumCol[j] += diff;
 
        // Update the count variable
        count += diff;
 
        // If ith row satisfied, increment ith
        // value for next iteration
        if (sumRow[i] == maxSum)
            ++i;
 
        // If jth column satisfied, increment
        // jth value for next iteration
        if (sumCol[j] == maxSum)
            ++j;
    }
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}

  // } Driver Code Ends