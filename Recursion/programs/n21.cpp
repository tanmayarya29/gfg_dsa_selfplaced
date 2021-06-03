#include <iostream>
using namespace std;
void n21(int n){
    if(n==0)return;
    cout<<n<<" ";
    n21(n-1);
}
void one2n(int n){
    if(n==0)return;
    one2n(n-1);
    cout<<n<<" ";
}
int main(){
    int n=3;
    n21(n);
    one2n(n);
}