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

//1. merge two sorted array
//time O(m+n) and aux O(m+n)
void merge(int a[],int b[],int n,int m){
    int res[n+m];
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            res[i+j]=a[i];
            i++;
        }
        else{
            res[i+j]=b[j];
            j++;
        }
    }
    while(i<n){
        res[i+j]=a[i];
        i++;
    }
    while(j<m){
        res[i+j]=b[j];
        j++;
    }
    for(int i=0;i<n+m;i++){
        cout<<res[i]<<" ";
    }
}

int main(){
    int arr[]={1,2,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int arr2[]={1,2,3,5,7};
    int n2=sizeof(arr2)/sizeof(arr[0]);
    // merge_sort(arr,n);
    merge(arr,arr2,n,n2);
    // for(int x:arr)cout<<x<<" ";
}