#include <iostream>
using namespace std;
//rec optimised euclidean fast modular version*****
int gcdREC(int a,int b){
    if(b%a==0)return a;
    return gcdREC(b%a,a);
}
//iter slow O(min(a,b)) 
int gcdITER(int a,int b){
    int res=min(a,b);
    while(res>0){
        if(a%res==0 && b%res==0)break;
        res--;
    }
    return res;
}

//euclidian slow differencive version
int gcdEUC(int a,int b){
    while(a!=b){
        if(a>b){
            a-=b;
        }else{
            b-=a;
        }
    }
    return a;
}

int main(){
    int a=6,b=86;
    cout<<gcdREC(a,b)<<endl;//*****
    cout<<gcdITER(a,b)<<endl;
    cout<<gcdEUC(a,b)<<endl;
}