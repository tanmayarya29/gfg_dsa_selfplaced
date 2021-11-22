#include <bits/stdc++.h>
using namespace std;

void print_boundary(vector<vector<int>>&mat)
{
    int R=mat.size();
    int C=mat[0].size();
    if(R == 1)
	{
		for(int i = 0; i < C; i++)
			cout << mat[0][i] << " ";
	}
	else if(C == 1)
	{
		for(int i = 0; i < R; i++)
			cout << mat[i][0] << " ";
	}
	else
	{
		for(int i = 0; i < C; i++)
			cout << mat[0][i] << " ";
		for(int i = 1; i < R; i++)
			cout << mat[i][C - 1] << " ";
		for(int i = C - 2; i >= 0; i--)
			cout << mat[R - 1][i] << " ";
		for(int i = R - 2; i >= 1; i--)
			cout << mat[i][0] << " ";
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
    print_boundary(v);
}