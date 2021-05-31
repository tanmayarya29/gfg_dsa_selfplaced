#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool isPrimeO(int num){//O(sqrtn)
if(num==1||(num!=2&&num%2==0)||(num!=3&&num%3==0))return false;
    for(auto i=5;i*i<=(num);i+=6){
        if(num%i==0||num%(i+2)==0){
            return false;
        }
    }
    return true;
}

void primesTillN(int n){//nsqrtn
    for(auto i=0;i<n;i++){
        if(isPrimeO(i))cout<<i<<" ";
    }
}

void soe(int n){//nloglogn
    vector<bool> isPrm(n+1,true);
    for(int i=2;i<=n;i++){
        if(isPrm[i]){
            cout<<i<<" ";
            for(int j=i*i;j<=n;j+=i){
                isPrm[j]=false;
            }
        }
    }
}

int main(){
    int n=20;
    // primesTillN(n);
    soe(n);
}