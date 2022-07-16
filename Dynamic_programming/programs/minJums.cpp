#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[],int n){
    if(n==1)return 0;
    int res=INT_MAX;
    for(int i=0;i<=n-2;i++){
        if(i+arr[i]>=n-1){
            int sub_res=minJumps(arr,i+1);
            if(sub_res!=INT_MAX)res=min(res,sub_res+1);
        }
    }
    return res;
}

int minJumpsdp(int arr[],int n){//theta n^2
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(arr[j]+j>=i){
                if(dp[j]!=INT_MAX){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
}


int main(){
    int arr[]={3,4,2,1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minJumps(arr,n)<<endl;
    cout<<minJumpsdp(arr,n)<<endl;

}