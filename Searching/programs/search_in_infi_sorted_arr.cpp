#include<iostream>
using namespace std;

int b_search(int arr[],int elem,int low,int high){
    int mid;
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

int search_in_infi_sorted_arr(int arr[],int elem){//Unbounded binary search
    if(arr[0]==elem)return 0;
    int i=1;
    while(arr[i]<elem)i*=2;
    if(arr[i]==elem)return i;
    return b_search(arr,elem,i/2+1,i-1);
  
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10},elem=8;
    cout<<search_in_infi_sorted_arr(arr,elem);
}