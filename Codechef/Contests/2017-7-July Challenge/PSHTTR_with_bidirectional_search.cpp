/*
  Problem 	:
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
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

typedef long long ll;
typedef vector<pair<int, int>> EDGES; // tuple< vertex, weight, bywho > || bywho = 0 if no one visited yet, 1 if visited by s, 2 if visited by t
typedef vector<pair<int, int>>::iterator EIT;
typedef map<pair<int, int>, int> MPH; // map to store edges

int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }

void BFS(queue<int>& q, EDGES adj[], int parent[], int visited[], int& meetpoint, const int who){
	int current = q.front();
	q.pop();
	for(EIT it = adj[current].begin(); it != adj[current].end(); ++it){
		if(!visited[it->first]){ // no body visited it
			visited[it->first] = who;
			parent[it->first] = current;
			q.push(it->first);
		} else if(visited[it->first] != who){
			meetpoint = it->first;
			parent[it->first] = current;
			return;
		}
	}
}

void solve(EDGES adj[], int n, int s, int t, int k, MPH& mph){
	queue<int> s_q, t_q;
	int s_parent[n], t_parent[n], meetpoint = -1, temp,ans, weight;
	int visited[n];
	memset(visited, 0, sizeof(visited));
	memset(s_parent, 0, sizeof(visited));
	memset(t_parent, 0, sizeof(visited));
	s_q.push(s);
	visited[s] = 1;
	
	t_q.push(t);
	visited[t] = 2;
	
	while(!s_q.empty() && !t_q.empty()){
		
		if(meetpoint == -1) BFS(s_q, adj, s_parent, visited, meetpoint, 1);
		if(meetpoint == -1) BFS(t_q, adj, t_parent, visited, meetpoint, 2);
		if(meetpoint != -1){
			ans = 0;
			temp = meetpoint;
			while(temp != s){
				weight = mph[mp(temp, s_parent[temp])];
				if(weight <= k) ans = ans ^ weight;
				temp = s_parent[temp];
			}
			temp = meetpoint;
			while(temp != t){
				weight = mph[mp(temp, t_parent[temp])];
				if(weight <= k) ans = ans ^ weight;
				temp = t_parent[temp];
			}
			printf("%d\n",ans);
			break;
		}
	}
}

int main(){
	int T;
	T = rin();
	while(T--){
		int n,x,y,c,m,u,v,k;
		n = rin();
	    EDGES adj[n+1];
	    MPH mph;
    	for(int i = 0;i<n-1;i++){
    		x = rin(), y = rin(), c = rin();
		    adj[x].pb(mp(y,c));
		    adj[y].pb(mp(x,c));
		    mph[mp(x,y)] = c;
		    mph[mp(y,x)] = c;
		}
		m = rin();
		for(int i = 0;i<m;i++){
			u = rin(), v = rin(), k = rin();
			solve(adj, n+1,u,v,k, mph);
		}		
	}
	return 0;
}

