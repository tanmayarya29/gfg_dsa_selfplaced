#include <bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>>&mat)
{
    int R=mat.size();
    int C=mat[0].size();
    for(int i = 0; i < R; i++)
    {
        for(int j = i+1; j < C; j++)
        {
                swap(mat[i][j], mat[j][i]);
        }
    }
}

void rotate_90(vector<vector<int>>&mat)
{
    int R=mat.size();
    int C=mat[0].size();
    transpose(mat);
    //step-1 -> transpose
    //step 2 reverse individual columns
    for(int i=0;i<R/2;i++){
        for(int j=0;j<C;j++){
            swap(mat[i][j],mat[R-i-1][j]);
        }
    }
     
}

int main()
{   
    vector<vector<int>> v={
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };
    rotate_90(v);
    for(auto i:v)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}