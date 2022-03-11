#include <iostream>
using namespace std;
bool isSubseq(string &s1,string &s2)
{
    int j=0;
    int n=s1.length(),m=s2.length();
    for(int i=0;i<n&&j<m;i++)
    {
        if(s1[i]==s2[j])
            j++;
    }
    return (j==m); 
}
int main(){
    string s1="civic",s2="cvc";
    if(isSubseq(s1,s2))
        cout<<"Yes";
    else
        cout<<"No";
}