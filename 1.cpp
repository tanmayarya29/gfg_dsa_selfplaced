#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define nl "\n"

bool sol(string a,string b,int n){
    if(a==b)return true;
    int b1=0,a1=0;
    for(int i=0;i<n;i++){
        if(b[i]=='1'){
            b1++;
        }
        if(a[i]=='1'){
            a1++;
        }
    }
    if(b1==0)return true;
    //
    bool res=true;
    char curr=b[0];
    for(int i=1;i<n;i++){
        if(b[i]==curr){
            break;
        }
        curr=='0'?curr='1':curr='0';
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string a,b;
         cin>>a>>b;
            if(sol(a,b,n)){
                cout<<"YES"<<nl;
            }
            else{
                cout<<"NO"<<nl;
            }
    }
    return 0;
}