#include <bits/stdc++.h>
using namespace std;

/*
variations of lis
1. minimum deletions to make array sorted -> len of arr - lis
2. max sum increasing sub sequence -> replace len with element sum in lis
int MSIS(int arr[], int n)
{
    int msis[n];
    for(int i=0; i<n; i++)
    {
        msis[i]  = arr[i];
        for(int j=0; j<i; j++)
        {
            if(arr[j] < arr[i])
            {
                msis[i] = max(msis[i], arr[i] + msis[j]);
            }
        }
    }
    int res = msis[0];
    for(int i=0; i<n; i++)
    {
        res = max(res, msis[i]);
    }
    return res;
}

3. max len bitonic sub sequence -> first inc then dec , use another lds array with lis arr, return max of lis[i]+lds[i]-1
4. building bridge(pair of cities)nlogn
max no of bridge w/o crossing
sol-> sort pair by 1st val if val are same check 2nd val, find lis using 2nd values
5. the longest chain of pairs
pair(a,b) a<b, find longest chain with inc order
sol-> sort by 1st val only,find lis by compairing 1st.second > 2nd.first
*/

int lis(int arr[], int n)
{ // theta n^2 time and theta n space
    int dp[n], res = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

//
int ceilIdx(int tail[], int l, int r, int x)
{
    while (r > l)
    {
        int m = (l + r) / 2;
        if (tail[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int lisFast(int arr[], int n)
{ // theta nlogn using bsearch
    int tail[n], len = 1;
    tail[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilIdx(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

int main()
{
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, n) << endl;
    cout << lisFast(arr, n) << endl;
}