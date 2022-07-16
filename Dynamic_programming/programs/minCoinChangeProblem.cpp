#include<bits/stdc++.h>
using namespace std;

//recursion
int minCoins(int coins[],int n,int val){
    if(val==0)return 0;
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        if(coins[i]<=val){
            int sub_res=minCoins(coins,n,val-coins[i]);
            if(sub_res!=INT_MAX)res=min(res,sub_res+1);
        }
    }
    return res;
}

//dp theta n^2
int minCoinsdp(int coins[],int n,int val){
    int dp[val+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                int sub_res=dp[i-coins[i]];
                if(sub_res!=INT_MAX)dp[i]=min(dp[i],sub_res+1);
            }
        }
    }
    return dp[val];
}

int main(){
    int coins[]={25,10,5};
    int n=sizeof(coins)/sizeof(coins[0]);
    cout<<minCoins(coins,n,30)<<endl;
    cout<<minCoinsdp(coins,n,30)<<endl;
}