#include<iostream>
using namespace std;

int maxSubarrSum(int arr[],int n){//naive//n2
   int res=arr[0];
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=i;j<n;j++){
            curr+=arr[j];
            res=max(res,curr);
        }
    }
    return res;
}

int maxSubarrSumFast(int arr[],int n){//efficient//n//kadens algo
    int maxEnding=arr[0],res=arr[0];
   for(int i=1;i<n;i++){
       maxEnding=max(maxEnding+arr[i],arr[i]);
       res=max(res,maxEnding);
   }
   return res;
}

int main(){
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<maxSubarrSum(arr,n);
    cout<<maxSubarrSumFast(arr,n);
}