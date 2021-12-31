#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vi>
#define vvl vector<vl>
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define rforn(i,n) for(int i=n-1;i>=0;i--)
#define rforn1(i,n) for(int i=n;i>=1;i--)
#define all(v) v.begin(),v.end()
#define mll map<ll,ll>
#define ss second
#define ASCII_SIZE 256
#define l endl
#define ff first

int main()
{
    fast
    ll t=1;
    ll n;
    cin>>t;
    here:
    while(t--){
    cin>>n;
    vector<ll> v(n);
    forn(i,n)
    cin>>v[i];
    //
    // for(ll i=0;i<n;i++){
    //     a[i]=v[i]%v[0];
    //     b[i]=v[i]%v[1];
    // }
    //
    ll ans=0;
    for(int i=0;i<n;i++){
        if(v[i]%v[0]==0){
            if(v[i+1]%v[0]==0){
        ans=0;
                
                break;
            }
            else{

        ans=v[0];
                i++;
            }

    }else 
        ans=0;
    

}
    for(int i=0;i<n;i++){
        if(v[i]%v[1]==0){
            if(v[i+1]%v[1]==0){
            ans=0;
                break;
            }
            else{
        ans=v[1];

                i++;
            }
    }
    else 
        ans=0;
    }
    cout<<ans<<endl;
}
	return 0;
}