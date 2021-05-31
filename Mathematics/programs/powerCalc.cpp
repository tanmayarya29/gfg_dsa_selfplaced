#include<iostream>
#include<vector>
using namespace std;
int power(int n,int p){//logn //auxsp logn
    // if (p==1) return n;
    // return n*power(n,p-1);
    if(p==0)return 1;
    int temp=power(n,p/2);
    temp*=temp;
    if(p%2==0){
        return temp;
    }else return temp*n;
}

int powerBin(int n,int p){//logn //auxsp 1
    int res=1;
    while(p>0){
        if(p&1){//p%2!=0
            res*=n;
        }
        n*=n;
        p>>=1;//p/=2
    }
    return res;
}

int main(){
    int n=5,p=4;
    cout<<power(n,p)<<endl;
    cout<<powerBin(n,p)<<endl;
}
