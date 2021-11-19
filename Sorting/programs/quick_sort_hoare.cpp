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

//quick sort using hoare partition
//1st index
//horse = 3xomuto in speed
// for improving worst case use int x=random (l,h) and swap (l,x)
int hoare_partition(int arr[],int l,int h){//O n timt n O 1 space
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}

void quick_sort_hoare(int arr[],int l,int h){
    if(l<h){
        int p=hoare_partition(arr,l,h);
        quick_sort_hoare(arr,l,p);
        quick_sort_hoare(arr,p+1,h);
    }
}




int main(){
    int a[] = {10,5,9,3,1,7,8,2,4,6};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort_hoare(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}