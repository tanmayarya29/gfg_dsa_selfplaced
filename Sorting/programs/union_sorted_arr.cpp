#include <iostream>
using namespace std;

void union_arr(int arr1[],int arr2[],int n1,int n2){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(i>0 && arr1[i]==arr1[i-1]){i++;continue;}
        if(j>0 && arr2[j]==arr2[j-1]){j++;continue;}
        if(arr1[i]<arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr1[i]>arr2[j]){
            cout<<arr2[j]<<" ";
            j++;
        }
        else{
            cout<<arr1[i]<<" ";
            i++;j++;
        }
    }
    while(i<n1){
        if(i>0 && arr1[i]!=arr1[i-1]){
            cout<<arr1[i]<<" ";
            i++;
        }
    }
    while(j<n2){
        if(j>0 && arr2[j]!=arr2[j-1]){
            cout<<arr2[j]<<" ";
            j++;
        }
    }
}

int main(){
    int arr1[]={1,2,2,3,3,3,4,6,6,6,6,6,6,6,6,6};
    int arr2[]={2,3,3,4,4,6,7,8,9};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    union_arr(arr1,arr2,n1,n2);
}