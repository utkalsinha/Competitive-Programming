/*
  Problem	:
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long int BIG;

class  Graph{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	int DFSUtil(int v, bool visited[]);
public:
	Graph(int V); // constructor
	void addEdge(int v, int w);
	int connectedComponents();	
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int Graph::DFSUtil(int v, bool visited[]){
	// mark the current node as visited
	int depth = 1;
	visited[v] = true;
	// Recur for all the verticies adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i!= adj[v].end();++i){
		if(!visited[*i]){
			depth += DFSUtil(*i,visited);
		}
	}
	return depth;
}

int Graph::connectedComponents(){
	// mark al the vertices as not visited
	int ans = -1,t;
	bool *visited = new bool[V];
	for(int v = 0;v<V;v++) visited[v] = false;
	for(int v = 0;v<V;v++){
		if(visited[v] == false){
			// count all reachable vertices from v
			t = DFSUtil(v,visited);
			if(ans <t) ans = t;
		}
	}
	return ans;
}

int main(){
	int V,E,u,v;
	scanf("%d %d",&V,&E);
	Graph g(V);
	FOR(i,E){
		scanf("%d %d",&u,&v);
		g.addEdge(u-1,v-1);
	}
	printf("%d\n",g.connectedComponents());
	return 0;
}



