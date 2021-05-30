#include<iostream>
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
void printPrimeFactors(int num){//O(sqrtn*logn)
    if(isPrimeO(num))cout<<num<<" ";
    for(int i=2;i*i<num;i++){
        if(isPrimeO(i)){
            int x=i;
            while(num%x==0){
                cout<<i<<" ";
                x*=i;
            }
        }
    }
}

//optimised
void printPrimeFact(int num){//O(sqrtn*logn)
    if(num<=1)return;
    for(int i=2;i*i<=num;i++){
        while(num%i==0){
            cout<<i<<" ";
            num/=i;
        }
    }
    if(num>1)cout<<num<<" ";
}

//optimised ++
void printPrimeFactO(int num){//theta sqrt n
    if(num<=1)return;
    while(num%2==0){
        cout<<2<<" ";
        num/=2;
    }
    while(num%2==0){
        cout<<2<<" ";
        num/=2;
    }
    for(int i=5;i*i<=num;i+=6){
        while(num%i==0){
            cout<<i<<" ";
            num/=i;
        }
        while(num%(i+2)==0){
            cout<<i+2<<" ";
            num/=(i+2);
        }
    }
    if(num>3)cout<<num<<" ";
}

int main(){
    int num=128;
    printPrimeFactors(num);
    printPrimeFact(num);
    printPrimeFactO(num);//*****
}