#include <bits/stdc++.h>
using namespace std;

void print_spiral(vector<vector<int>>&mat)
{
    int row=mat.size();
    int col=mat[0].size();
    int i=0,j=0;
    while(i<row){
        // cout<<"("<<i<<","<<j<<")";
        if(j==col){
            i++;
            while(j>0){
                j--;
                cout<<mat[i][j]<<" ";
            }
        }
        else {
            while(j<col){
                cout<<mat[i][j]<<" ";
                j++;
            }
            i++;
        }
    }  
}

void print_spiral2(vector<vector<int>>&mat)
{
    int row=mat.size();
    int col=mat[0].size();
    for(int i=0;i<row;i++){
        if(i%2==0){
            for(int j=0;j<col;j++){
                cout<<mat[i][j]<<" ";
            }
        }
        else{
            for(int j=col-1;j>=0;j--){
                cout<<mat[i][j]<<" ";
            }
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
    print_spiral(v);
    print_spiral2(v);
}