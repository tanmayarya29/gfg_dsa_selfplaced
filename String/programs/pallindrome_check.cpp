#include <iostream>
using namespace std;
bool isPal(string &s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}
int main(){
    string s="civic";
    if(isPal(s))
        cout<<"Yes";
    else
        cout<<"No";
}