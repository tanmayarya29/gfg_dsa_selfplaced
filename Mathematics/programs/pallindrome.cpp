#include<iostream>
#include<cmath>
using namespace std;
//theta of len of num
int reverse(int num){
    int rev=0;
    while(num>0){
        rev=rev*10+num%10;
        num/=10;
    }
    return rev;
}

bool isPallindrome(int num){
    // cout<<num<<" "<<reverse(num);
    return(num==reverse(num));
}

int main(){
    int num=121;
    cout<<isPallindrome(num)<<endl;
}