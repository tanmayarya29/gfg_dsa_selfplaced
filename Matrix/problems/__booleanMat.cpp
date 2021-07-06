// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &mat)
    {
        // code here 
        int R=mat.size();
        int C=mat[0].size();
         // variables to check if there are any 1
    // in first row and column
    bool row_flag = false;
    bool col_flag = false;
 
    // updating the first row and col if 1
    // is encountered
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 && mat[i][j] == 1)
                row_flag = true;
 
            if (j == 0 && mat[i][j] == 1)
                col_flag = true;
 
            if (mat[i][j] == 1) {
 
                mat[0][j] = 1;
                mat[i][0] = 1;
            }
        }
    }
 
    // Modify the input matrix mat[] using the
    // first row and first column of Matrix mat
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
 
            if (mat[0][j] == 1 || mat[i][0] == 1) {
                mat[i][j] = 1;
            }
        }
    }
 
    // modify first row if there was any 1
    if (row_flag == true) {
        for (int i = 0; i < C; i++) {
            mat[0][i] = 1;
        }
    }
 
    // modify first col if there was any 1
    if (col_flag == true) {
        for (int i = 0; i < R; i++) {
            mat[i][0] = 1;
        }
    }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


  // } Driver Code Ends