#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define nl "\n"

string sol(int arr[],int n,int iq){
    string res="";
    for(int i=0;i<n;i++){
        if(arr[i]<=iq){
            res+="1";
        }
        else{
            res+="0";
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]>iq && iq!=0){
            res[i]='2';
            --iq;
        }
    }
    int lastOccuranceOf1=-1;
    for(int i=n-1;i>=0;i--){
        if(res[i]=='2'){
            lastOccuranceOf1=i;
            break;
        }
    }
    if(lastOccuranceOf1==-1)return res;
    
    for(int i=lastOccuranceOf1+1;i<n;i++){
            res[i]='0';
    }
    
    for(int i=0;i<n;i++){
        if(res[i]=='2'){
            res[i]='1';
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,iq;
        cin>>n>>iq;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<sol(arr,n,iq)<<endl;
    }
    return 0;
}