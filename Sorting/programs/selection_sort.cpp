#include <iostream>
using namespace std;
/*
1. theta n^2
2. Does less memory write than quick_sort, merge_sort, heap_sort, insertion_sort etc.
3. basic idea for heap sort
4. not stable-same lement changes its position
5. inplace-not requires extra space
*/
//fin min elem and put at its posn
void selection_sort(int *a, int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main(){
    int arr[]={2,1,4,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    for(int x:arr)cout<<x<<" ";
}