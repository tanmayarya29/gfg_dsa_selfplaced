#include<bits/stdc++.h>
using namespace std;

long long solve(int x, vector<int> c, int n) {
long long dp[n-1][4];
for(int i=0;i<n-1;i++){
for(int j=0;j<4;j++)
dp[i][j] = 1e12;
}

dp[0][0] = c[0];

for(int i=1;i<n-1;i++){
dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]})+c[i];
dp[i][1] = dp[i-1][0]+x;
dp[i][2] = dp[i-1][1]+x;
dp[i][3] = dp[i-1][2]+x;
}

return min({dp[n-2][0],dp[n-2][1],dp[n-2][2],dp[n-2][3]}) + c[n-1];

}

int main(){
    string s;
cin>>s;
sort(s.begin(),s.end());
cout<<s[0];
}

