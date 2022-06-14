#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int sol(int a[],int n){
    //count of most repeating element
    int cnt[n];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        if(cnt[i]>maxi){
            maxi=cnt[i];
        }
    }
    return maxi;
}



int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<sol(a,n)<<endl;
    }
}