#include <bits/stdc++.h>
using namespace std;

class cls
{
public:
    void boolMat(vector<vector<int>> &armat)
    {

        int X = armat.size();
        int Y = armat[0].size();

        bool rowmrk = false;
        bool colmrk = false;

        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (i == 0 && armat[i][j] == 1)
                    rowmrk = true;


                if (armat[i][j] == 1)
                {

                    armat[i][0] = 1;
                }
            }
        }

        for (int i = 1; i < X; i++)
        {
            for (int j = 1; j < Y; j++)
            {

                if (armat[0][j] == 1 || armat[i][0] == 1)
                {
                    armat[i][j] = 1;
                }
            }
        }

        if (rowmrk == true)
        {
            for (int i = 0; i < Y; i++)
            {
                armat[0][i] = 1;
            }
        }

        
    }
};

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    int inp;
    cin >> inp;
    while (inp--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> mat(row);
        for (int i = 0; i < row; i++)
        {
            mat[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
            }
        }

        cls obj;
        obj.boolMat(mat);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}