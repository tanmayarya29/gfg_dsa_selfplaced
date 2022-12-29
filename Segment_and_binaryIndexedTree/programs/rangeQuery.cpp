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

int getSumRec(int qs, int qe, int ss, int se, int si, int tree[])// theta logn
{
    if (se < qs || ss > qe)
        return 0;
    if (qs <= ss && qe >= se)
        return tree[si];
    int mid = (ss + se) / 2;
    return getSumRec(qs, qe, ss, mid, 2 * si + 1, tree) + getSumRec(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

int main()
{
    int arr[] = {10, 20, 30, 40}; // [100, 30, 70, 10, 20, 30, 40]
    int n = sizeof(arr) / sizeof(arr[0]);
    int tree[4 * n]; // 4*n is the upper bound of the size of the segment tree
    fill(tree, tree + 4 * n, 0);
    buildSegmentTree(0, n - 1, 0, arr, tree);
    cout << getSumRec(0, 2, 0, 3, 0, tree);
}