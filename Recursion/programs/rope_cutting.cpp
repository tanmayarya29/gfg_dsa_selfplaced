#include<iostream>
using namespace std;
//***
int rope_cut(int n,int a,int b,int c){//into max pieces//timeO(3^n)//dp has btr implementation
    if(n<0)return -1;
    if(n==0)return 0;
    int res=max(rope_cut(n-a,a, b, c),max(rope_cut(n-b,a, b, c),rope_cut(n-c,a, b, c)));
    if (res==-1)return -1;
    return res+1;
}

int main(){
    int n=5,a=2,b=5,c=1;//9 2 2 2
    cout<<rope_cut(n,a,b,c)<<endl;
}