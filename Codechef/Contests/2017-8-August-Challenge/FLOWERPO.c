/*
  Problem 	: Codechef - August Challenge - 2017 - https://www.codechef.com/AUG17/problems/FLOWERPO
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
  
  P.S. 		: FOR 20 MARKS (Reducing the problem to a Bellman Ford algorithm in a directed graph).
*/
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define MAXV 3001
#define INF 999999999999999999
//#define INF 0x3f3f3f3f
 
typedef long long ll;
//int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
ll ans1, ans2, mat[MAXV][MAXV], nwdist[MAXV], prevdist[MAXV], parent[MAXV];
ll a[MAXV], n;
 
ll min(ll a, ll b){
	return (a<b)?a:b;
}
 
ll findStrength(ll s, ll t, ll b){
	prevdist[s] = 0;
	nwdist[s] = 0;
	
	for(ll i=0;i<b;i++){
		for(ll j=0;j<n;j++){
			prevdist[j] = nwdist[j];
		}
		
		for(ll u = 0; u<n; u++){
			for(ll v = 0; v<n; v++){
				if(prevdist[u] + mat[u][v] < nwdist[v]){
					nwdist[v] = prevdist[u] + mat[u][v];
					parent[v] = u;
				}
			}
		}
	}
	return nwdist[t];
}
 
void genmat(){
	ll diff;
	for(ll i=0;i<n;i++){
		for(ll j = i+1;j<n;j++){
			diff = abs(a[i]-a[j]);
			mat[i][j] = mat[j][i] = 1L * diff * diff;
		}
	}
}
 
void display(){
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			printf("%8lld ", mat[i][j]);
		}
		printf("\n");
	}
}
 
void solve(){
	ll b, c, left = 0, right = 0, maxinfluence, cur, totalinfluence, rightindex, leftindex;
	n = rinl(), b = rinl(), c = rinl();
	for(ll i=0;i<n;i++) a[i] = rinl();
	
	genmat();
	//display();
	if(b>n)b = n-1; // if does not work then delete it.
	c = c-1; // my code is 0-based index
	
	//================================== first part ====================================
		// left first than check right
	if(a[c] - a[0] > a[n-1] - a[c]){
		left = right = 0;
		
		left = findStrength(c, 0, b);
		maxinfluence = c;
		cur = c-1;
		
		while(cur >=0 && parent[cur] == c) maxinfluence = cur, cur--;
		totalinfluence = abs(a[c] - a[maxinfluence]);
		
		// find right index
		//printf("totalinfluence = %lld\n", totalinfluence);
		rightindex = c;
		
		while(rightindex < n && (abs(a[rightindex] - a[c]) <= totalinfluence)) {
			//printf("totalinfluence = %lld, (abs(a[rightindex] - a[c]) = %lld\n", totalinfluence, (abs(a[rightindex] - a[c])));
			rightindex++;	
		}
		//printf("rightindex = %lld, findStrength(rightindex-1, n-1, b-1) = %lld\n", rightindex, findStrength(rightindex-1, n-1, b-1));
		if(rightindex <= n-1) right = findStrength(rightindex-1, n-1, b-1);
		ans1 = left + right;
		printf("%lld\n", ans1);
	}
	else {
	//================================== second part ====================================
		// right first than check left
		left = right = 0;
		right = findStrength(c, n-1, b);
		maxinfluence = c;
		cur = c+1;
		
		while(cur <n && parent[cur] == c) maxinfluence = cur, cur++;
		
		// find left index
		leftindex = c;
		while(leftindex >= 0 && (abs(a[leftindex] - a[c]) <= totalinfluence)) leftindex--;
		
		if(leftindex >= 0) left = findStrength(leftindex+1, 0, b-1);
		ans2 = left + right;
		printf("%lld\n", ans2);
	}
}
 
void reset(){
	memset(mat,0, sizeof(mat));
	memset(a,0, sizeof(a));
	for(ll i=0;i<MAXV;i++) nwdist[i] = INF, prevdist[i] = INF, parent[i] = INF;
}
 
int main(){
	ll T = rinl();
	while(T--){
		ans1 = ans2 = 0L;
		reset();
		solve();
	}
	return 0;
} 
