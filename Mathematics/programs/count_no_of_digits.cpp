#include<iostream>
#include<cmath>
using namespace std;
//1. iterative theta of len of no
int nodIter(int num){
    int count=1;
    while(num/=10){
        count++;
    }
    return count;
}
//2. recursive(not for num=0) theta of len of no
int nodRec(int num){
    if(num==0){
        return 0;
    }
    return 1+nodRec(num/10);
}
//3. logrithmic/optimal/oneLiner***** theta of constant
int nodLogOpt(int num){
    if(num==0)return 1;
    return floor(log10(num)+1);
}


int main(){
    int num=12345678;
    cout<<nodIter(num)<<endl;
    cout<<nodRec(num)<<endl;
    cout<<nodLogOpt(num)<<endl;///best
}