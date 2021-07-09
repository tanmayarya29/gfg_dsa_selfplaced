// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);

// Position this line where user code will be pasted

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++) cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--) {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            } else {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}
// } Driver Code Ends


// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree
// int getMid(int s, int e) { return s + (e -s)/2; }
 
/* A recursive function to get the sum of values in the given range
    of the array. The following are parameters for this function.
 
    st --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
            0 is passed as root is always at index 0
    ss & se --> Starting and ending indexes of the segment represented
                by current node, i.e., st[si]
    qs & qe --> Starting and ending indexes of query range */
int getSumUtil(ll *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes which have the given
index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i --> index of the element to be updated. This index is
            in the input array.
diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(ll *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}
void updateValue(int arr[], ll *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        // cout<<"Invalid Input";
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
//Function to update a value in input array and segment tree.
// void updateValue(int *arr, ll *st, int n, int index, int new_val) 
// {
//     // add code here
// }
ll getsum(ll *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        // cout<<"Invalid Input";
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

//Function to return sum of elements in range from index qs (query start)
//to qe (query end).
// ll getsum(ll *st, int n, int l, int r)
// {
//     // add code here
// }
