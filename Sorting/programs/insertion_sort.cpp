#include <iostream>
using namespace std;
/*
1. Big-O (n^2) in worst case when array is reverse sorted
2. InPlace and stable
3. Stable: Elements at same position in the array are not reordered
4. Used in practice for small arrays (Tim sort and Intra sort)
5. Big-O of N in best case when array is sorted
*/
//left part is always sorted and right part is unsorted and we put element at its correct position in sorted array
void insertion_sort(int *a, int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
int main(){
    int arr[]={2,1,4,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(int x:arr)cout<<x<<" ";
}