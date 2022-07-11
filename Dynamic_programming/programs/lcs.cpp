//no of subseq = 2^n
//dimension of dp table depends of no of changing parameters in recursion//here 2 // n1 and n2
#include<bits/stdc++.h>
using namespace std;

//1. recursion exponential or 2^n
int lcs1(string s1,string s2,int n1,int n2){//matching from last to first
    if(n1==0||n2==0)return 0;
    else if(s1[n1-1]==s2[n2-1])return 1+lcs1(s1,s2,n1-1,n2-1);
    else return max(lcs1(s1,s2,n1-1,n2),lcs1(s1,s2,n1,n2-1));
}

//2. memoisation theta(n1n2) time
int memo[1000][1000];// or [n1+1] [n2+1]
int lcs2(string s1,string s2,int n1,int n2){
    if(memo[n1][n2]!=-1){
        return memo[n1][n2];
    }
    if(n1==0||n2==0){
        memo[n1][n2]=0;
    }
    else{
        if(s1[n1-1]==s2[n2-1])memo[n1][n2]=1+lcs2(s1,s2,n1-1,n2-1);
        else
            memo[n1][n2]=max(lcs2(s1,s2,n1-1,n2),lcs2(s1,s2,n1,n2-1));
    }
    return memo[n1][n2];
}

//3. tabulation theta n1n2 time
int lcs3(string s1,string s2,int n1,int n2){
    int dp[n1+1][n2+1];
    //filling 1st row and col as 0
    for(int i=0;i<=n1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n2;i++){
        dp[0][i]=0;
    }
    //calculating dp
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

//variations of lcs
/*
1. diff utility(difference bewtween two files) like in git comparision of commits
2. minimum insertions or deletions to make s1 as s2//n1-lcs+n2-lcs
3. shortest common supersequence//lcs + diffeerent char in b/w in sequence
4. longest pallindromic subsequence//s1=string s2=reverse of string -> find lcs done
5. longest repeating subsequence//s1=s2=string //modify condition s1[m]==s2[n] && m!=n in lcs
6. space optimised dp solution of LCS//we just need least row and col so linear space needed as 2m or 2n
7. printing LCS//dp matrix traversal from bottom right to top left 
*/

int main(){
    string s1="AGGTAB",s2="GXTXAYB";
    int n1=6,n2=7;
    cout<<lcs1(s1,s2,n1,n2)<<endl;
    //
    memset(memo,-1,sizeof(memo));
    cout<<lcs2(s1,s2,n1,n2)<<endl;
    //
    cout<<lcs3(s1,s2,n1,n2);


}