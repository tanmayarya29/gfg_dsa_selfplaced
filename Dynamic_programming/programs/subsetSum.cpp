#include<bits/stdc++.h>
using namespace std;
//2^n time
int countSubsets(int arr[],int n,int sum){
    if(n==0){
        return sum==0?1:0;
    }
    return countSubsets(arr,n-1,sum-arr[n-1])+countSubsets(arr,n-1,sum);
}

//dp time n space nxsum
int countSubsetsdp(int arr[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=sum;i++)dp[0][i]=0;
    //
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}

int main(){
    int arr[]={10,5,2,3,6};
    int n=sizeof(arr)/sizeof(arr[0]),sum=8;
    cout<<countSubsets(arr,n,sum)<<endl;
    cout<<countSubsetsdp(arr,n,sum)<<endl;
}