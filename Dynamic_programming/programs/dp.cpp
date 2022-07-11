/*
dp-an optimisation over recursion
the idea is to reuse the solution of subproblems when there are overlapping subproblems
1-Memoisation(top down)
2-Tabulaiton(bottom up)

Applications-
1. Bellman ford algo(shortest path from source to all destinations)
2. floyd warshall algo(shortest path between each pair of vertices in a graph)
3. Diff utility(LCS) - used in git version management
4. Search nearest/closed words (Edit distance)
5. Resource allocation (0-1 knapsack)
*/

#include<bits/stdc++.h>
using namespace std;

//1. Nth Fibonacci using memoisation or top down 
int arr[1000];
int fibomem(int n){
    if(arr[n]==-1){
        int res;
        if(n==0||n==1)return n;
        res=fibomem(n-1)+fibomem(n-2);
        arr[n]=res;
    }
    return arr[n];
}

//2. Nth Fibonacci using tabulation or bottom up 
int fibotab(int n){
    int tab[n+1];
    tab[0]=0;
    tab[1]=1;
    for(int i=2;i<=n;i++){
        tab[i]=tab[i-1]+tab[i-2];
    }
    return tab[n];
}

int main(){
    memset(arr,-1,sizeof(arr));
    cout<<fibomem(10)<<endl;
    cout<<fibotab(10)<<endl;
}