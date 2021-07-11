#include <bits/stdc++.h>
using namespace std;

void getShadow(int arr[], int n)
{
	int rep,miss;
	for (int i = 0;i<n;i++) {
		if (arr[abs(arr[i]) - 1]>0)arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
		else rep=abs(arr[i]);
	}
	for (int i = 0;i<n;i++) {
		if (arr[i]>0)miss=(i+1);
	}
    cout<<rep<<" "<<miss<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];  
	    getShadow(arr, n);
    }
	
}

