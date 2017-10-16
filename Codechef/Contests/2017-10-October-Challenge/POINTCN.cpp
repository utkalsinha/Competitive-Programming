#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
 
unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}
 
const int MX = 1000;
 
int C[MX][MX];
int H[MX][MX];
int ans[MX][MX];
typedef long long int ll;
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
 
void printop(){
	for(int i=0;i<MX;i++) {
		for(int j = 0; j<MX;j++) printf("%d", ans[i][j]);
		printf("\n");
	}
}
 
int getcostpat(int pati){
	int ret = 0;
	if(pati==1) for(int i=0, j = 1; i<MX-1; i++, j++) ret += C[i][j];
	
	return ret;
}
 
void updatepat(int pati){
	memset(ans, false, sizeof(ans));
	if(pati==1) for(int i=0, j = 1; i<MX-1; i++, j++) C[i][j] = C[j][i] = 1;
}
 
int getcost(int index, int deg, int n){
	int ret = 0;
 
	bool visited[n];
	memset(visited, false, sizeof(visited));
	
	visited[index] = true;
	
	stack<int> stk;
	stk.push(index);
	
	int u, deg_counter, min_c_val, min_c_index;
	bool found;
	int ver_c = n-1;
	
	while(ver_c && !stk.empty()){
		u = stk.top(), stk.pop();
		deg_counter = deg;
		
		while(ver_c && deg_counter>0){
			min_c_val = INT_MAX;
			found = false;
			for(int v = 0;v<n;v++){
				if(v != u && !visited[v] && C[u][v]<min_c_val) {
					min_c_val = C[u][v];
					min_c_index = v;
					found = true;
				}
			}
			if(!found) break;
			else{
				deg_counter--;
				stk.push(min_c_index);
				visited[min_c_index] = true;
				ver_c--;
				ret += C[u][min_c_index];
			}
		}
	}	
 
	return ret;
}
 
int getMinHCol(int n){
	int index, minv = INT_MAX, temps;
	
	for(int i=n-1;i>=2;i--){
		minv = INT_MAX;
		temps = 0;
		
		for(int j = 0; j<n; j++){
			temps += H[j][i];	
		}
		if(minv > temps) minv = temps, index = i;
	}
	return index;
}
 
void updateans(int index, int deg, int n){
	bool visited[n];
	memset(visited, false, sizeof(visited));
	memset(ans, false, sizeof(ans));
	
	visited[index] = true;
	
	stack<int> stk;
	stk.push(index);
	
	int u, deg_counter, min_c_val, min_c_index;
	bool found;
	int ver_c = n-1;
	
	while(ver_c && !stk.empty()){
		u = stk.top(), stk.pop();
		deg_counter = deg;
		
		while(ver_c && deg_counter>0){
			min_c_val = INT_MAX;
			found = false;
			for(int v = 0;v<n;v++){
				if(v != u && !visited[v] && C[u][v]<min_c_val) {
					min_c_val = C[u][v];
					min_c_index = v;
					found = true;
				}
			}
			if(!found) break;
			else{
				deg_counter--;
				stk.push(min_c_index);
				visited[min_c_index] = true;
				ver_c--;
				ans[u][min_c_index] = ans[min_c_index][u] = 1;
			}
		}
	}	
}
 
int find_min_deg_vertex(){ // pair<vertex, degree>
	int ret;
	int minv = INT_MAX;
	
	for(int i=0;i<MX; i++){
		for(int j = 2;j<MX; j++){
			if(minv > H[i][j]) minv = H[i][j], ret = i;
		}
	}	
	return ret;
}
 
int main() {
	int T = rin();
	//scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n = rin(), Cmax = rin(), Hmax = rin();
		//scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
			//scanf("%llu %llu", &s[0], &s[1]);
			s[0] = rinl(), s[1] = rinl();
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}
		
		for (int i = 0; i < n; i++) {
			//scanf("%llu %llu", &s[0], &s[1]);
			s[0] = rinl(), s[1] = rinl();
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
		
		// solve here
		int min_h_colv = getMinHCol(n);
		int min_ver_index = find_min_deg_vertex();
		
		
		int curmaxval = INT_MAX, newmaxval, tmv;
		memset(ans, 0, sizeof(ans));		
		
		
		// manual patterns start
//		newmaxval = 0;
//		tmv = getcostpat(1);
//		if(newmaxval > tmv) updatepat(1), newmaxval = tmv;
//		tmv = getcostpat(2);
//		if(newmaxval > tmv) updatepat(2);
		// manual patterns end
		
		
		int degr;
		for(int k = 0, index = min_ver_index; k<4; k++, index = (index+5)%n)
		for(int counter = 0; counter<10; counter++){
			degr = min_h_colv-counter;
			if(degr<2) degr = n-1, min_h_colv = n-2;
			newmaxval = getcost(index, degr, n);
			if(newmaxval < curmaxval){
				curmaxval = newmaxval;
				updateans(index, degr, n);
			}
		}
		
		printop();
	}
	
	return 0;
} 
