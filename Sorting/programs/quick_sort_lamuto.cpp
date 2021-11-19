#include <iostream>
using namespace std;
/*
1. D n C
2. worst case O(n^2)
3. despite of O(n^2) in wrst case it is fastest :
    a. in place
    b. cache friendly
    c. average case O(n log n)
    d. tail recursive
4. partition is key function (naive, lomuto, hoare)
*/

//quick sort using lamuto partition

//pivot last element or swap the given pivot with last element to make it last element

// for improving worst case use int x=random (l,h) and swap (h,x)
int lamuto_partition(int arr[],int l,int h){//O n timt n O 1 space
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void quick_sort_lamuto(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lamuto_partition(arr, l, h);
        quick_sort_lamuto(arr, l, p - 1);
        quick_sort_lamuto(arr, p + 1, h);
    }
}


int main(){
    int a[] = {10,5,9,3,1,7,8,2,4,6};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort_lamuto(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}