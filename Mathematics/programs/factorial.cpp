#include<iostream>
using namespace std;
#define ull unsigned long long

ull factIter(int num){//O(num)//better as takes theta 1 aux space
    if(num==0)return 1;
    long long res=num;
    while(--num){
        res*=num;
    }
    return res;
}

ull factRec(int num){//O(num)//theta n aux space so worse then iter
    if (num==0) return 1;
    return num*factRec(num-1);
}

int main(){
    int num=5;
    cout<<factRec(num)<<endl;
    cout<<factIter(num)<<endl;

}