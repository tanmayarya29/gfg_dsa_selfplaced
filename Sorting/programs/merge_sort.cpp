#include <iostream> 
using namespace std;
//merge sort
/*
1. Divide and conquer algo(divide->sort and merge)
2. stable algorithm not inplace
3. theta of nlog n and bigO of n space
***4. well suited for linked list, works in O(1) space
5. used in external sorting
6. In general for arrays quick sort outperforms mergesort

*/
// void merge(int a[],int low,int mid,int high){
//     int tmid=mid+1;
//     int auxarr[high],k=0;
//     for(int i=low;i<high;i++)auxarr[i]=a[i];
//     while(low<=mid && tmid<high){
//         if(auxarr[low]<=auxarr[tmid])a[k]=auxarr[low++];
//         else {a[k]=auxarr[tmid++];}
//         k++;
//     }
//     while(low<=mid)a[k]=auxarr[low++],k++;
//     while(tmid<high)a[k]=auxarr[tmid++],k++;
// }

void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}

void merge_sort(int a[],int l,int r){
    if(r>l){//atleat 2 elements
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int arr[]={1,7,2,6,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n);
    for(int x:arr)cout<<x<<" ";
}