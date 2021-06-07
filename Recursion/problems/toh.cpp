// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    int steps=0;
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        //no fo mvt is 2^n-1
    steps++;
    if(n==1){
    cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
    return steps;
    }
    toh(n-1,from,aux,to);
    cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
    toh(n-1,aux,to,from);
    }
};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends