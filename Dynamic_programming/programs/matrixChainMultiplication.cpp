#include<bits/stdc++.h>
using namespace std;

int matMul(int arr[],int i,int j){
    if(i+1==j)return 0;
    int res=INT_MAX;
    for(int k=i+1;k<j;k++){
        res=min(res,matMul(arr,i,k)+matMul(arr,k,j)+arr[i]*arr[k]*arr[j]);
    }
    return res;
}
//n^3 time n^2 space
int matMuldp(int arr[],int n){
    int dp[n][n];
    for(int i=0;i<n-1;i++){
        dp[i][i+1]=0;
    }
    for(int gap=2;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j=i+gap;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
            }
        }
    }
    return dp[0][n-1];
}



int main(){
    int arr[]={2,1,3,4};//it represents mat of dim 2x1,1x3,3x4//res=20 operation
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<matMul(arr,0,n-1)<<endl;
    cout<<matMuldp(arr,n)<<endl;
}