#include<iostream>
using namespace std;

int normalMaxSum(int arr[],int n){
    int maxEnding=arr[0],res=arr[0];
   for(int i=1;i<n;i++){
       maxEnding=max(maxEnding+arr[i],arr[i]);
       res=max(res,maxEnding);
   }
   return res;
}

int maxCirSumSubarr(int arr[],int n){//efficient//n
//normal sum
    int maxNormal=normalMaxSum(arr,n);
    if(maxNormal<0)return maxNormal;
//circular sum
    int arr_sum=0;
    for(int i=0;i<n;i++){
        arr_sum+=arr[i];
        arr[i]=-arr[i];
    }
    int max_circular=arr_sum+normalMaxSum(arr,n);
    return max(maxNormal,max_circular);
}

int main(){
    int arr[]={8,-4,3,-5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxCirSumSubarr(arr,n);
}