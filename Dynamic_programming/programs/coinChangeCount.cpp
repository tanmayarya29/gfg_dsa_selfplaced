#include<bits/stdc++.h>
using namespace std;
//recursion same as 0-1 knapsack
int getCount(int coins[],int n,int sum){
    //base cases
    if(sum==0)return 1;
    if(n==0)return 0;
    int res=getCount(coins,n-1,sum);//dont include coin
    if(coins[n-1]<=sum){//include coin
        res+=getCount(coins,n,sum-coins[n-1]);
    }
    return res;
}

//dp tabulation
int getCountdp(int coins[],int n,int sum){
    int dp[sum+1][n+1];
    for(int i=1;i<=sum;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }
    //we run for each sum then coin // vice versa wont work as we have 0 sum still looking for coins
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(coins[j-1]<=i){
                dp[i][j]+=dp[i-coins[j-1]][j];
            }
        }
    }
    return dp[sum][n];
}


int main(){
    int coins[]={1,2,3};
    int n=3,sum=4;
    cout<<getCount(coins,n,sum)<<endl;
    cout<<getCountdp(coins,n,sum)<<endl;
}