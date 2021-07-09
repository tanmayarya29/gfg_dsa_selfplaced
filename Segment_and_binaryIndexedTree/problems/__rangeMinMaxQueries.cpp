// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int getMid(int s, int e) {  return s + (e -s)/2;  }

void constructSTUtil(int *arr, int ss, int se, PII *st, int si)
{
    if (ss == se)
    {
        st[si].first = st[si].second = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si*2+1);
    constructSTUtil(arr, mid+1, se, st, si*2+2);
    
    st[si].first = min(st[si*2+1].first, st[si*2+2].first);
    st[si].second = max(st[si*2+1].second, st[si*2+2].second);
    
    return;
}

PII *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    PII *st = new PII[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

void updateValue(int *, PII *, int, int, int);
PII getMinMax(PII *, int *, int, int, int);

// Position this line where user code will be pasted

int main(){
	int t;
	cin>>t;
	while(t--){
		int num, query;
		cin>>num>>query;
		int arr[num];
		for(int i=0;i<num;i++)
			cin>>arr[i];
		
		PII *st = constructST(arr, num);
		int L, R, index , val;
		char type;
		while(query--){
		    cin.ignore(INT_MAX, '\n');
		    cin>>type;
		    if(type == 'G'){
		        cin>>L>>R;
		        PII ans = getMinMax(st, arr, num, L, R);
		        cout<<ans.first<<" "<<ans.second<<endl;
		    }
		    else{
		        cin>>index>>val;
		        updateValue(arr, st, num, index, val);
		    }
		    
		}	
	}
	return 0;
}
// } Driver Code Ends


//User function template for C++

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// PII :  return pair denoting min,max respectively.
// index : given index to update with new_val


//Function to update a value in input array and segment tree.
//Back-end complete function template for C++


//recursive function to update the nodes which have given index in their range. 
void updateValueUtil(PII *st, int ss, int se, int i, int new_val, int si)
{
    //base cases
    if (i < ss || i > se)
        return;
    if(ss == se){
        st[si].first = st[si].second = new_val;
        return;
    }
    
    //if the input index is in range of this node then we update
    //the value of the node and its children. 
    int mid = getMid(ss, se);
    updateValueUtil(st, ss, mid, i, new_val, 2*si + 1);
    updateValueUtil(st, mid+1, se, i, new_val, 2*si + 2);
    
    st[si].first = min(st[si*2+1].first, st[si*2+2].first);
    st[si].second = max(st[si*2+1].second, st[si*2+2].second);
    
    return;
}

//Function to update a value in input array and segment tree.
//It uses updateValueUtil() to update the value in segment tree.
void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
    //base case for invalid input.
    if (index < 0 || index > n-1){
        return;
    }
    arr[index] = new_val;
    
    //updating the value of nodes in segment tree.
    updateValueUtil(st, 0, n-1, index, new_val, 0);
}

//recursive function to get the minimum and maximum value in
//a given range of array indexes.
PII getMinMaxUtil(PII *st, int ss, int se, int qs, int qe, int si)
{
    //if segment of this node is a part of given range then we 
    //return the minimum and maximum node of the segment.
    if (qs <= ss && qe >= se)
        return st[si];
        
    //if segment of this node is outside given range, we return INT_MAX,INT_MIN.
    if (se < qs || ss > qe)
        return PII{INT_MAX, INT_MIN};
    
    //if a part of this segment overlaps with the given range, we call
    //the function recursively for the children nodes.    
    int mid = getMid(ss, se);
    PII first = getMinMaxUtil(st, ss, mid, qs, qe, 2*si+1);
    PII second = getMinMaxUtil(st, mid+1, se, qs, qe, 2*si+2);
    return PII{min(first.first, second.first), max(first.second, second.second)};
}

//Function to return minimum and maximum of elements in range from index
//qs (quey start) to qe (query end). It mainly uses MaxMinUtill().
PII getMinMax(PII *st,int *arr, int n, int qs, int qe)
{
    //base case for invalid input.
    if (qs < 0 || qe > n-1 || qs > qe){
        return PII{-1, -1};
    }
 
    return getMinMaxUtil(st, 0, n-1, qs, qe, 0);
}