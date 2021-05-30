#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num){//O(sqrtn)
if(num==1)return false;
    for(auto i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
//optimised 3x
bool isPrimeO(int num){//O(sqrtn)
if(num==1||(num!=2&&num%2==0)||(num!=3&&num%3==0))return false;
    for(auto i=5;i<=sqrt(num);i+=6){
        if(num%i==0||num%(i+2)==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num=1031;
    cout<<isPrime(num)<<endl;
    cout<<isPrimeO(num)<<endl;
}