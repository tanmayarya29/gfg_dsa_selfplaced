// Binary search tree or Fenwick tree faster than segment tree and takes log n space
/**
 * 1. Used for fixed input array and multiple queries of the following types:
 *      a.Prefix operations (sum, product, xor, or, etc) in logn time
 *      b.update a value
 *      c. range queries as rangeSum(i,j)=prefixSum(j)-prefixSum(i-1)
 * 2. It is actually an array but the concept is tree based.
 * 3. Requires O(nlogn) preprocessing time and theta n auxillary space.
 * 4. Cant be used in range max/min queries
 */

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
    for (int i = 1; i <= n; i++)
        cout << bit[i] << " ";
}
