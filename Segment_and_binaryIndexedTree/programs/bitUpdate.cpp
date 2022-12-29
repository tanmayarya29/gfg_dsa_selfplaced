#include <iostream>
using namespace std;

// O(nlogn) for construction of the tree
void update(int i, int x, int n, int bit[])
{
    i = i + 1;
    while (i <= n)
    {
        bit[i] += x;
        i += (i & (-i)); // adding 1 to last set bit gives next index
    }
}

// O(logn)
void updateVal(int i, int x, int n, int arr[], int bit[])
{
    int diff = x - arr[i];
    arr[i] = x;
    i = i + 1;
    while (i <= n)
    {
        bit[i] += diff;
        i += (i & (-i)); // adding 1 to last set bit gives next index
    }
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
    updateVal(2, 35, 5, arr, bit);
    for (int i = 1; i <= n; i++)
        cout << bit[i] << " ";
}
