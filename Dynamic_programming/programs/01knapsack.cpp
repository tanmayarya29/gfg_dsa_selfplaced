#include<bits/stdc++.h>
using namespace std;

//2^n time complexity
int knapsack(int w,int wt[],int val[],int n){
    if(n==0||w==0)return 0;
    if(wt[n-1]>w){
        return knapsack(w,wt,val,n-1);
    }
    else{
       return max(knapsack(w,wt,val,n-1),knapsack(w-wt[n-1],wt,val,n-1)+val[n-1]);
    }
}

//w*n time complexity pseudopolynomial time complexity if w is large recursive becomes better
int knapsackdp(int w,int wt[],int val[],int n){
    //dp[i][j] represents the max value we can get if we take upto i items and weight/knapsack capacity is j
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0)dp[i][j]=0;
            else if(wt[i-1]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
        }
    }
    return dp[n][w];
}

int main(){
    int w=10;
    int val[]={10,40,30,50};
    int wt[]={5,4,6,3};
    int n=sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(w,wt,val,n)<<endl;
    cout<<knapsackdp(w,wt,val,n)<<endl;

}