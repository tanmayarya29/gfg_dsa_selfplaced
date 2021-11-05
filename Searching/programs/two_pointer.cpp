#include<iostream>
#include<algorithm>
using namespace std;

int b_search(int arr[],int elem,int n){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
    if(elem==arr[mid])
        return mid;
    else if(elem>mid){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    return -1;
}

bool pair_sum_unsorted(int arr[],int n,int sum)
{
    for(int i=0;i<n;i++){
        int temp=sum-arr[i];
        if(b_search(arr,temp,n))
            return true;
    }
    return false;
}
bool pair_sum_sorted(int arr[],int n,int sum)
{
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==sum)return true;
        else if(arr[i]+arr[j]<sum)i++;
        else j--;
    }
    return false;
}

bool pair_sum_sorted2(int arr[],int i,int n,int sum)
{
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==sum)return true;
        else if(arr[i]+arr[j]<sum)i++;
        else j--;
    }
    return false;
}

bool triplet_sum(int arr[],int n,int sum){
    //for unsorted
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int temp=sum-arr[i];
        if(pair_sum_sorted2(arr,i+1,n,temp))
            return true;
    }
    return false;
}



int main(){
    int arr[]={3,5,9,2,5,8,10,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int pairsum=17;
    cout<<pair_sum_unsorted(arr,n,pairsum)<<endl;
    int arr2[]={1,2,3,4,5,6,7};
    n=sizeof(arr2)/sizeof(arr2[0]);
    pairsum=3;
    cout<<pair_sum_sorted(arr2,n,pairsum)<<endl;
    int arr3[]={3,5,5,6,7,4};
    n=sizeof(arr3)/sizeof(arr3[0]);
    pairsum=10;
    cout<<triplet_sum(arr3,n,pairsum)<<endl;
}