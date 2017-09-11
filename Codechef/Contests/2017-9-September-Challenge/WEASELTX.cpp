/*
  Problem 	: Codechef -September Challenge (https://www.codechef.com/SEPT17/problems/WEASELTX)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pb push_back
#define MAX2 262150
 
typedef long long ll;
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int n, q, u, v, s, levels, parent[MAX2], child;
vector<int> tree[MAX2];
ll arr[MAX2], narr[MAX2], temp, finallimit;
int periodicity;
ll res[MAX2];
bool visited[MAX2];
 
inline void take_inputs(){
	n = rin(), q = rin();
	for(int i=0;i<n-1;i++) u = rin(), v = rin(), tree[u].pb(v), tree[v].pb(u);
	for(int i=0;i<n;i++) arr[i] = rinl();
}
 
inline void BFS_compress(){
	list<int> qu, qu2;
	qu.pb(0);
	levels = 0;
	
	narr[levels] = arr[0];
	parent[0] = -1;
	
	while(!qu.empty()){
		temp = 0, levels++;
		
		while(!qu.empty()){
			s = qu.front(), qu.pop_front();
			
			for(int i = 0; i<tree[s].size(); i++){
				child = tree[s][i];
				if(child != parent[s]){
					parent[child] = s;
					temp ^= arr[child];
					qu2.pb(child);
				}
			}
		}
		narr[levels] = temp;
		swap(qu,qu2);
	}
}
 
void processqueries(){
	ll qv, m, val, tm;
	int switchv, base2powVal, upper2powVal, numof4blocksRepeat, repeating_block_size, blocklimit;
	
	res[0] = narr[0];
	visited[0] = true;
	
	while(q--) {
		qv = rinl();
		m = qv%periodicity;
		
		// new code start
		if(!visited[m]){
			vector<int> locations;
			base2powVal = (1<<(int)(floor(log2(m))));
			upper2powVal = (1<<(int)(ceil(log2(m))));
			//numof4blocks = 
			
			val = 0;
			switchv = m%4;
			
			bool f = true;
			
			
			if(base2powVal == upper2powVal){
				f = false;
				for(int j=0; j<levels; j+= upper2powVal)  {
					val ^= narr[j];
				}
			}
			
			// iterate all blocks
			if(f){
				
				// find first block indices
				blocklimit = upper2powVal - m + 1;
				tm = m-1;
				val = 0;
				for(int j=0;j<levels && j<blocklimit;j++) {
					if((~(tm+j) & j) == 0) {
						val ^= narr[j];
						locations.pb(j);
					}
				}
				
				
				repeating_block_size = upper2powVal;
				int p = repeating_block_size, k;
				while(p<levels){
					k = p;
					for(int g = 0; g<locations.size() && k<levels; g++, k++){
						val = val ^ narr[p+ locations[g]];
					}
					p = p + repeating_block_size;
				}
			}
			// iterate all blocks [done]
			
			res[m] = val;
			visited[m] = true;
		}
		// new code end
		
		printf("%lld\n", res[m]);
	}
}
 
int main(){
	take_inputs();
	BFS_compress();
	periodicity = (1<<(int)(ceil(log2(levels))));
	processqueries();
	
	return 0;
} 
