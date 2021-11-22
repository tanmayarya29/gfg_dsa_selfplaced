#include <bits/stdc++.h>
using namespace std;

bool serchInSortedMatrix(auto mat, int R, int C,int x)
{

    int i = 0, j = C - 1;
    while(i < R && j >= 0)
    {
        if(mat[i][j] == x)
            {cout<<"("<<i+1<<", "<<j+1<<")"<<endl;
            return true;}
        else if(mat[i][j] > x)
            j--;
        else
            i++;
    }
    return false;
}

int main(){
    vector<vector<int>> mat={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int R=mat.size();
    int C=mat[0].size();
    int elem=11;
    cout<<serchInSortedMatrix(mat,R,C,elem);
}