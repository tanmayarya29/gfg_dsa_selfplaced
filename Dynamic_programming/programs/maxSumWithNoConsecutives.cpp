#include<bits/stdc++.h>
using namespace std;

//recursive 2^n time
int maxSum(int arr[],int n){
    if(n==1)return arr[0];
    else if(n==2)return max(arr[0],arr[1]);
    else return max(maxSum(arr,n-1),maxSum(arr,n-2)+arr[n-1]);
}

// //dp O(n) time n space
// int maxSumdp(int arr[],int n){
//     if(n==1)return arr[0];
//     int dp[n+1];
//     dp[1]=arr[0];
//     dp[2]=max(arr[0],arr[1]);
//     for(int i=3;i<=n;i++){
//             dp[i]=max(dp[i-1],dp[i-2]+arr[i-1]);
//     }
//     return dp[n];
// }

//dp with O(1)space
int maxSumdp(int arr[],int n){
     if(n==1)return arr[0];
    int dp[3];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=3;i<=n;i++){
            dp[2]=max(dp[1],dp[0]+arr[i-1]);
            dp[0]=dp[1];
            dp[1]=dp[2];
    }
    return dp[2];
}

int main(){
    int arr[]={10,5,15,20,2,30};//10 10 25 25 27 60
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr,n)<<endl;
    cout<<maxSumdp(arr,n)<<endl;
}