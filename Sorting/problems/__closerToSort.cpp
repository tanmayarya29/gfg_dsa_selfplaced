// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// arr[]: input array
// N: size of array
// x: element to find index
//Function to find index of element x in the array if it is present.
int binarySearch(int arr[], int l, int r, int x)
{
if (r >= l)
{
        int mid = l + (r - l) / 2;
  
        // If the element is present at 
        // one of the middle 3 positions
        if (arr[mid] == x) 
            return mid;
        if (mid > l && arr[mid - 1] == x)
            return (mid - 1);
        if (mid < r && arr[mid + 1] == x) 
            return (mid + 1);
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 2, x);
  
        // Else the element can only be present 
        // in right subarray
        return binarySearch(arr, mid + 2, r, x);
}
  
// We reach here when element is not present in array
return -1;
}

int closer(int arr[], int N, int x) {
    
    //Your code here
    return binarySearch(arr, 0, N - 1, x);
    
}

// { Driver Code Starts.


int main() {

    int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		int *arr;
		arr = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int x;
		scanf("%d", &x);
		printf("%d\n", closer(arr, n, x) );
	}
	return 0;

}  // } Driver Code Ends