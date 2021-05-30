#include<iostream>
using namespace std;
#define ull unsigned long long
//naive approach theta n very slow:(
ull factIter(int num){//O(num)//better as takes theta 1 aux space
    int res=num;
    while(--num){
        res*=num;
    }
    return res;
}

int countTrailZerosOfFact(int num){
    ull fact=factIter(num);
    int count=0;
    while(fact%10==0){
        count++;
        fact/=10;
    }
    return count;
}


//optimised :)
int countTrailZerosOfFactO(int num){
    int res=0;
    for(auto i=5;i<=num;i*=5){
        res=res+num/i;
    }
    return res;
}

int main(){
    int num=251;//ans 62
    // cout<<countTrailZerosOfFact(num)<<endl;
    cout<<countTrailZerosOfFactO(num)<<endl;
}