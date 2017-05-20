#include <stdio.h>
#include <limits.h>

#define V 4

int getMinDistNode(int dist[], bool sptSet[]){
	int minVal = INT_MAX, min_index;
	for(int i = 0;i<V;i++){
		if(!sptSet[i] && minVal > dist[i]){
			minVal = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void dijkstra(int graph[V][V], int src){
	int dist[V];
	bool sptSet[V];
	for(int i = 0;i<V;i++){
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for(int i = 0;i<V-1;i++){
		int u = getMinDistNode(dist, sptSet);
		sptSet[u] = true;
		for(int v = 0;v<V;v++){
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u]+graph[u][v]) dist[v] = dist[u] + graph[u][v];
		}
	}
	printf("Distance values are:\n");
	for(int i = 0;i<V;i++){
		printf("%d \t\t %d\n", i, dist[i]);
	}
}

int main(){
	int graph[V][V] = {
		{0,1,1,1},
		{1,0,1,0},
		{1,1,0,1},
		{1,0,1,0}
	};
	dijkstra(graph, 0);
	
	return 0;
}
