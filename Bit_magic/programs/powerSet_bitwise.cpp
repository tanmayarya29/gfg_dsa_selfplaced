#include<iostream>
using namespace std; 

void powerSet(string s){//time->2^n x n
    int n=s.length();
    int powSize=1<<n;
    for(int i=0;i<powSize;i++){
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0)cout<<s[j];
        }
        cout<<endl;
    }
}

int main(){
    string s="abc";
    powerSet(s);

}