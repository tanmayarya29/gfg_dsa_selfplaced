
#include<bits/stdc++.h> 
using namespace std;
int cntPar(int *a, int n, int mid) 
{ 
    int res = 0; 
    for (int i = 0; i < n; ++i) 
        res += upper_bound(a+i, a+n, a[i] + mid)-(a + i + 1); 
    return res; 
} 

int getKsmall(int a[], int n, int k) 
{ 
    sort(a, a+n); 
    int low = a[1] - a[0]; 
    for (int i = 1; i <= n-2; ++i) 
        low = min(low, a[i+1] - a[i]); 
    int high = a[n-1] - a[0]; 
  
    while (low < high) 
    { 
        int mid = (low+high)>>1; 
        if (cntPar(a, n, mid) < k) 
            low = mid + 1; 
        else
            high = mid; 
    } 
  
    return low; 
} 
int main() 
{ 
   ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];  
	    cout<<getKsmall(arr,n,k)<<endl;
    }
} 