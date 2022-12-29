#include <iostream>
using namespace std;
/**
 * @param
 * ss - segment start
 * se - segment end
 * si - index of segment in array
 */
int buildSegmentTree(int ss, int se, int si, int arr[], int tree[])
{
    if (ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se) / 2;
    tree[si] = buildSegmentTree(ss, mid, 2 * si + 1, arr, tree) +
               buildSegmentTree(mid + 1, se, 2 * si + 2, arr, tree);
    return tree[si];
}

void update(int ss, int se, int i, int si, int diff, int tree[]) // O logn
{
    if (i < ss || i > se)
        return;
    tree[si] += diff;
    if (se > ss)
    {
        int mid = (ss + se) / 2;
        update(ss, mid, i, 2 * si + 1, diff, tree);
        update(mid + 1, se, i, 2 * si + 2, diff, tree);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40}; // [100, 30, 70, 10, 20, 30, 40]
    int n = sizeof(arr) / sizeof(arr[0]);
    int tree[4 * n]; // 4*n is the upper bound of the size of the segment tree
    fill(tree, tree + 4 * n, 0);
    buildSegmentTree(0, n - 1, 0, arr, tree);
    // update
    int new_val = 25, i = 1;
    int diff = new_val - arr[i];
    update(0, n - 1, i, 0, diff, tree);
    for (int i = 0; i < 4 * n; i++)
        cout << tree[i] << " ";
}