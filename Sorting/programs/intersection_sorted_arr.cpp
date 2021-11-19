#include <iostream>
using namespace std;

void intersection(int arr1[],int arr2[],int n1,int n2){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(i>0 && arr1[i]==arr1[i-1]){
            i++;
            continue;
        }
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;j++;
        }
        else if(arr1[i]<arr2[j])i++;
        else j++;
    }
}

int main(){
    int arr1[]={1,2,2,3,3,3,4,6,6,6,6,6,6,6,6,6};
    int arr2[]={2,3,3,4,4,6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    intersection(arr1,arr2,n1,n2);
}