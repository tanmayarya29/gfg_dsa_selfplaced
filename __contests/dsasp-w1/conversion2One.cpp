#include <bits/stdc++.h>
using namespace std;
int CntStp(int n,int cnt =0)
{
	while(n>1){
		cnt++;
		if (n % 2 == 0)//even nos
			{n /= 2;}
		else if (n % 4 == 1||n==3)//odd and 3
			{n -= 1;}
		else{//odd
			n += 1;}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
	    cout<<CntStp(n)<<endl;
    }
}
