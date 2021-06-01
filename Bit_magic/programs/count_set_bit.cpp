#include<iostream>
#include<cmath>
using namespace std;

int countSetBitNaive(int n){//time=no of bits in bin rep of n
    int res=0;
    //w b/w opr
    while(n){
    res+=((1&n)==1);
    n>>=1;
    }

    //w/o b/w opr
    //odd nos hv last bit as 1
    // while(n){
    //     res+=(n%2!=0);
    //     n/=2;//for removing last bit we do n/=2 or n>>=1;
    // }

    return res;
}

int countSetBitBrianKern(int n){//time=set bit count
    int res=0;
    while(n){
        n=(n&(n-1));//*7=111 & 6=110 = 110
        res++;
    }
    return res;
}

int countSetBitLookUpTable(int n){//***time=o(255)for 32 bit
    int table[256];
    //initialise
    table[0]=0;
    for(int i=1;i<=255;i++){
        table[i]=(i&1)+table[(i/2)];
    }
    //count
    int res=table[n&0xff];
    n>>=8;
    res+=table[n&0xff];
    n>>=8;
    res+=table[n&0xff];
    n>>=8;
    return res;
        
    }

int main(){
    int n=5;
    cout<<countSetBitNaive(n)<<endl;
    cout<<countSetBitBrianKern(n)<<endl;
    cout<<countSetBitLookUpTable(n)<<endl;//best
}