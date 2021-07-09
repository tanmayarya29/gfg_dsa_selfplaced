#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int left_petrol=0;
        int petrol=0;
        int distance=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
        distance=p[i].distance+distance;
        petrol+=p[i].petrol;
        left_petrol+=p[i].petrol-p[i].distance;
        if(left_petrol<0)
        {
        left_petrol=0;
        ans=i+1;
        }
        }
        if(distance>petrol)return -1;
        else return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends