#include <iostream>
using namespace std;

// O(nlogn) for construction of the tree
void update(int i, int x, int n, int bit[])
{
    i = i + 1;
    while (i <= n)
    {
        bit[i] += x;
        i += (i & (-i));
    }
}

int getSum(int i, int bit[])
{
    int res = 0;
    while (i)
    {
        res += bit[i];
        i = i - (i & (-i));// getting parent which we get by setting of last set bit
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int bit[n + 1];
    for (int i = 0; i <= n; i++)
    {
        bit[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        update(i, arr[i], n, bit);
    }
    //
    cout << getSum(4, bit) << " ";
}
