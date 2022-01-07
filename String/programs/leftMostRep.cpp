#include<iostream>
#include<climits>
using namespace std;
//BEST 
int leftMostRep(string &s){//index of left most rep char
    int n=s.length();
    bool a[256];
    fill(a,a+256,false);
    int minI=-1;
    for(int i=n;i>=0;i--){
        if(!a[s[i]]){
            a[s[i]]=true;
        }else{
            minI=i;
        }
    }
    return minI;
}
//efficient approach 1
int leftMostRep1(string &s){//index of left most rep char
    int n=s.length();
    int a[256];
    fill(a,a+256,-1);
    int minI=INT_MAX;
    for(int i=0;i<n;i++){
        if(!a[s[i]]){
            a[s[i]]=i;
        }else{
            minI=min(minI,a[s[i]]);
        }
    }
    return (minI==INT_MAX)?-1:minI;
}

int main(){
    string s="civi";
    cout<<leftMostRep(s)<<endl;
}