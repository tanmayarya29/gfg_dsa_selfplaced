#include<iostream>
using namespace std;

void toh(int n,char a,char b,char c){
    //no fo mvt is 2^n-1
    if(n==1){
        cout<<"Move 1 from "<<a<<" to "<<c<<endl;
        return;
    }
    toh(n-1,a,c,b);//using c as aux move from a to b
    cout<<"Move "<<n<<" from "<<a<<" to "<<c<<endl;
    toh(n-1,b,a,c);//using a as aux move from b to c
}


int main(){
    int disks=5;
    toh(disks,'a','b','c');
}
