// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int n, int m) 
    {
        vector<int> res;
        // code here 
        int sr=0,er=n-1,sc=0,ec=m-1;
    while(sr<=er && sc<=ec){
        //for row start
        for(int col=sc;col<=ec;col++){
            // cout<<a[sr][col]<<" ";
            res.push_back(a[sr][col]);
        }
        sr++;
        //for col end
        for(int row=sr;row<=er;row++){
            // cout<<a[row][ec]<<" ";
            res.push_back(a[row][ec]);
            
        }
        ec--;
        //for row end
        for(int col=ec;col>=sc;col--){
            // cout<<a[er][col]<<" ";
            res.push_back(a[er][col]);
            
        }
        er--;
        //for col start
        for(int row=er;row>=sr;row--){
            // cout<<a[row][sc]<<" ";
            res.push_back(a[row][sc]);
            
        }
        sc++;
    }
    res.resize(m*n);
    return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends