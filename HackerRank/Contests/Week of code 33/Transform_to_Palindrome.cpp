/*
  Problem : HackerRank - Week of Code 33 - https://www.hackerrank.com/contests/w33/challenges/transform-to-palindrome
  Author : Utkal Sinha
  Contact : info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif

#define pb push_back
#define mp make_pair
#define MAXV 100001

vector<vector<int>> components;
unordered_multimap<int,int> compMat;

inline void rd_int(int &x){ register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }

void addEdge(vector<int> adj[], int u, int v){
	adj[u].pb(v);
	adj[v].pb(u);
}

void DFSUtil(int u, vector<int> adj[], vector<bool>& visited, vector<int>& tempset){
	visited[u] = true;
	tempset.pb(u);
	for(int i = 0;i<adj[u].size();i++){
		if(visited[adj[u][i]] == false){
			DFSUtil(adj[u][i], adj, visited, tempset);
		}
	}
}

void DFS(vector<int> adj[], int N){
	vector<bool> visited(N, false);
	for(int u = 1;u<N;u++){
		if(visited[u] == 0){
			vector<int> tempset;
			DFSUtil(u,adj,visited,tempset);
			components.pb(tempset);
		}
	}
}

void FillcompMat(){
	int len = components.size(),i,j,k;
	vector<int>::iterator it1,it2;
	for(i = 0;i<len;i++){
		it1 = components[i].begin();
		while(it1 != components[i].end()){
			it2 = it1 + 1;
			
			while(it2 != components[i].end()){
				int a = *it1;
				int b = *it2;
				compMat.insert(mp(*it1,*it2));
				compMat.insert(mp(*it2,*it1));
				
				++it2;
			}
			++it1;
		}
	}
}

bool is_belong_to_same_group(int& a, int& b){
	auto range = compMat.equal_range(a);
	unordered_multimap<int,int>::iterator it;
	for(it = range.first; it!= range.second; ++it){
		if(it->second == b) return true;
	}
	
	return false;	
}

int main(){
	int n,k,m,i,j,u,v;
	rd_int(n),rd_int(k),rd_int(m);
	
	vector<int> adj[n+1];
	for(i = 0;i<k;i++){
		rd_int(u),rd_int(v);
		addEdge(adj,u,v);
	}
	int str[m];
	for(i = 0;i<m;i++) rd_int(str[i]);
		
	// find connected components
	DFS(adj,n+1);
	FillcompMat();
	
	// solve by dp
	int dp[m][m];
	memset(dp,0,sizeof(dp));

	i = 0;
	j = m-1;
	
	for(int gap = 1;gap<m;gap++){
		for(i = 0, j = gap;j<m;i++,j++){
			if(str[i] != str[j] && !is_belong_to_same_group(str[i], str[j])){
				dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
			} else dp[i][j] = dp[i+1][j-1];
		}
	}
	
	printf("%d\n",m-dp[0][m-1]);
	
	
	return 0;
}

