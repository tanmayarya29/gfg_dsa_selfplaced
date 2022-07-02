//dont work for -ve weight as we get wrong answers early
//if weight added to every edges o/p changed as no of edges chnged
//but if each w8 is multiplied by some value then sortest path remains same
//delete key not supported so hard to implement using library functions
// time - (v+e)logv using minheap else theta v square

#include <bits/stdc++.h> 
using namespace std; 
#define V 4
//improve using priority queue
vector<int> djikstra(int graph[V][V],int src) 
{ 

	vector<int> dist(V,INT_MAX);
	dist[src]=0;
	vector<bool> fin(V,false);

	for (int count = 0; count < V-1 ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!fin[i]&&(u==-1||dist[i]<dist[u]))
		        u=i;
		fin[u] = true; 
		
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && fin[v] == false) 
				dist[v] = min(dist[v],dist[u]+graph[u][v]); 
	} 
    return dist;
} 

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: djikstra(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 
