#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isPrfctSq(int n)
{
    return(ceil(sqrt(n)-floor(sqrt(n)))==0);
}

void getClcstPrfctSq(int n)
{
    int grtr,lsr;
    int n1=n+1;
    while(1){//upr bound
        if (isPrfctSq(n1)) {
            grtr = n1;
            break;
        }
        else n1++;
    }

    n1 = n - 1;
    while (1) {//lwr bound
        if (isPrfctSq(n1)) {
            lsr = n1;
            break;
        }
        else n1--;
    }
    if (grtr - n > n - lsr)
        cout<<lsr<<endl;
    else
        cout<<grtr<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        getClcstPrfctSq(n);
    }
}
