#include<bits/stdc++.h>
using namespace std;


vector<int> naiveSearch(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    vector<int>res;
    for(int i=0;i<n-m+1;i++){//hello n=5 lo m=2 0-3 so n-m+1=3 
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==m)cout<<i<<" ";
        }
    return res;
}

int main(){
    string text="hello",pattern="lo";
    for(auto i : naiveSearch(text,pattern))cout<<i<<" ";
}