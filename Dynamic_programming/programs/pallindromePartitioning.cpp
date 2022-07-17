#include <iostream>
#include <limits.h>
using namespace std;

bool isPalindrome(string input, int start, int end)
{

    while (start < end)
    {
        if (input[start] != input[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// rec
int palPart(string s, int i, int j)
{
    if (isPalindrome(s, i, j))
        return 0;
    int res = INT_MAX;
    for (int k = i; k < j; k++)
    {
        res = min(res, palPart(s, i, k) + palPart(s, k + 1, j) + 1);
    }
    return res;
}

// dp - O(n^3) time//ispal arr can optimise code
int palPartdp(string str)
{
    int n = str.length();

    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;

            if (isPalindrome(str, i, j))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{

    string s = "geek";

    cout << palPart(s, 0, s.length() - 1) << endl;
    cout << palPartdp(s);

    return 0;
}