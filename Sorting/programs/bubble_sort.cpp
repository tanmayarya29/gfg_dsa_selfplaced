#include<iostream>
using namespace std;
/*
1. Stable 
2. In-place
3. best case O(n)
4. worst case O(n^2) 
*/

//largest element gets to its crct posn on each pass
void bubble_sort(int *arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//if no elem is swapped, then array is sorted
void bubble_sort_optimised(int *arr, int n)
{
    bool swapped=false;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
        if(!swapped)
            break;
    }
}


int main(){
    int arr[]={2,1,4,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    for(int x:arr)cout<<x<<" ";

}