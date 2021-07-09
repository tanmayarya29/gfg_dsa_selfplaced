// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

using namespace std;

// Function to find gcd of 2 numbers.
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

// get mid
int getMid(int s, int e) {
    return s + (e - s) / 2;
}

// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
int constructST(int arr[], int st[], int ss, int se, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = getMid(ss, se);
    st[si] = gcd(constructST(arr, st, ss, mid, si * 2 + 1),
                 constructST(arr, st, mid + 1, se, si * 2 + 2));
    return st[si];
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
int *constructSegmentTree(int arr[], int n) {
    int height = (int) (ceil(log2(n)));
    int size = 2 * (int) pow(2, height) - 1;
    int *st = new int[size];
    constructST(arr, st, 0, n - 1, 0);
    return st;
}


 // } Driver Code Ends
// User function template in C++

// st : segment tree
// n : size of the given array
// l and r : range to find gcd i.e L and R respectively


class Solution
{
   public:
    //recursive function to get gcd of given range of array indexes.
    int findGcd(int ss, int se, int qs, int qe, int si, int st[]) 
    {
        //if segment of this node is outside the given range, we return 0.
        if (ss > qe || se < qs) 
        return 0;
        
        //if segment of this node is a part of given range, we return st[si].
        if (qs <= ss && qe >= se)
        return st[si];
        
        //if a part of this segment overlaps with the given range, we call
        //the function recursively for the children nodes.
        int mid = ss + (se - ss) / 2;
        return gcd(findGcd(ss, mid, qs, qe, si * 2 + 1, st),
                   findGcd(mid + 1, se, qs, qe, si * 2 + 2, st));
    }
    
    //Function to find gcd of given range.
    int findRangeGcd(int ss, int se, int st[], int n) 
    {
        //base case for invalid input.
        if (ss < 0 || se > n - 1 || ss > se) {
            return -1;
        }
        return findGcd(0, n - 1, ss, se, 0, st);
    }
    
    //recursive function to update nodes which have given index in their range.
    void updateValueUtil(int ss,int se,int index,int new_val,int si, int st[])
    {
        //base cases
        if (index < ss || index > se) return;
        if (se == ss) {
            st[si] = new_val;
            return;
        }
        
        //if the input index is in range of this node then we update
        //the value of the node and its children.
        int mid = getMid(ss, se);
        if (index <= mid)
            updateValueUtil(ss, mid, index, new_val, 2 * si + 1, st);
        else
            updateValueUtil(mid + 1, se, index, new_val, 2 * si + 2, st);
    
        st[si] = __gcd(st[si * 2 + 1], st[si * 2 + 2]);
    }
    
    //Function to update a value in input array and segment tree.
    //It uses updateValueUtil() to update the value in segment tree.
    void updateValue(int index, int new_val, int *arr, int st[], int n)
    {
        //base case for invalid input.
        if (index < 0 || index > n - 1) {
            return;
        }
        arr[index] = new_val;
        
        //updating the value of nodes in segment tree.
        updateValueUtil(0, n - 1, index, new_val, 0, st);
    }

};

// { Driver Code Starts.

// Driver program to test above functions
int main() {
    int t;
    cin >> t;

    while (t--) {

        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Build segment tree from given array
        int *st = constructSegmentTree(a, n);
        int type;
        while (q--) {
            // cin.ignore(INT_MAX, '\n');
            cin >> type;

            if (type == 0) {
                int l, r;
                cin >> l >> r;
                Solution obj;
                cout << obj.findRangeGcd(l, r, st, n) << endl;
            } else {
                int ind, val;
                cin >> ind >> val;
                Solution obj;
                obj.updateValue(ind, val, a, st, n);
            }
        }
    }

    return 0;
}  // } Driver Code Ends