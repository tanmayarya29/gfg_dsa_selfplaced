// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    struct Interval
    {
        int buy;
        int sell;
    };
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n)
    {
        vector<vector<int> > result;
      //Prices must be given for at least two days else return the empty result.
        if (n == 1)    
            return result;
     
        int count = 0;
     
        //Creating solution vector.
        Interval sol[n/2 + 1];
     
        //Traversing through given price array.
        int i = 0;
        while (i < n-1)
        {
            //Finding Local Minima. Note that the limit of loop is (n-2)
            //as we are comparing present element to the next element. 
            while ((i < n-1) && (A[i+1] <= A[i]))
                i++;
     
            //If we reach the end, we break the loop as no further
            //solution is possible.
            if (i == n-1)
                break;
     
            //Storing the index of minima which gives the day of buying stock.
            sol[count].buy = i++;
     
            //Finding Local Maxima. Note that the limit of loop is (n-1)
            //as we are comparing present element to previous element.
            while ((i < n) && (A[i] >= A[i-1]))
                i++;
     
            //Storing the index of maxima which gives the day of selling stock.
            sol[count].sell = i-1;
     
            //Incrementing count of buy/sell pairs.
            count++;
        }
        
        if (count == 0)
            return result;
        else
        {
            //Storing the buy/sell pairs in a list.
            for (int i = 0; i < count; i++){
                vector<int> temp;
                temp.push_back(sol[i].buy);
                temp.push_back(sol[i].sell);
                result.push_back(temp);
            }

        }
        //returning the result.
        return result;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends