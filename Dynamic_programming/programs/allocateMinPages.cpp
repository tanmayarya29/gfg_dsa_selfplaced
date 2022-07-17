//minimise max pages allocated
//only contagious pages can be allocated
//n-1Ck-1 ways

#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=arr[i];
    }
    return sum;
}

int allocate(int arr[],int n,int k){
    if(k==1)return sum(arr,0,n-1);
    if(n==1)return arr[0];
    int res=INT_MAX;
    for(int i=1;i<n;i++){
        res=min(res,max(allocate(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}

//dp//n^3*k time //best time is binary search with nlogsum time
int allocatedp(int arr[],int n,int k){
    int dp[k+1][n+1];
    for(int i=1;i<=n;i++)
        dp[1][i]=sum(arr,0,i-1);
    for(int i=1;i<=k;i++)
        dp[i][1]=arr[0];
        
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            int res=INT_MAX;
            for(int p=1;p<j;p++){
                res=min(res,max(dp[i-1][p],sum(arr,p,j-1)));
            }
            dp[i][j]=res;
        }
    }
    return dp[k][n];
}

int main(){
    int arr[]={10,20,30,40};
    int k=2,n=sizeof(arr)/sizeof(arr[0]);
    cout<<allocate(arr,n,k)<<endl;
    cout<<allocatedp(arr,n,k)<<endl;
}