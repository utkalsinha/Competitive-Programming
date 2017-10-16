/*
  Problem 	: https://www.codechef.com/OCT17/problems/CHEFCCYL
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
#include <bits/stdc++.h>
using namespace std;
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define pb push_back
#define mp make_pair
typedef long long int ll;
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
inline void findforwardsum(vector<int> all_cycles[], ll forwards[], int cur_cycle){
	forwards[0] = 0;
	for(int i = 1; i<all_cycles[cur_cycle].size(); i++){
		forwards[i] = forwards[i-1] + all_cycles[cur_cycle][i-1];
	}
}
 
inline void findbackwardsum(vector<int> all_cycles[], ll backwards[], int cur_cycle){
	backwards[0] = 0;
	int sz = all_cycles[cur_cycle].size();
	for(int i = sz-1; i>=1; i--){
		backwards[i] = backwards[(i+1)%sz] + all_cycles[cur_cycle][i];
	}
}
 
void preprocess(vector<int> all_cycles[], int cl[], int acl[], int gc[], int n, vector<ll > cl_intercycledistances[], vector<ll > acl_intercycledistances[], ll cl_gcdist[], ll acl_gcdist[]){
	int clp, aclp;
 
	for(int i=0;i<n;i++){
		
		ll temp_val_cl, temp_val_acl;
		ll forwards[all_cycles[i].size()], backwards[all_cycles[i].size()];
		findforwardsum(all_cycles, forwards, i); // done
		findbackwardsum(all_cycles, backwards, i); // done
		
		// fill individual cycle's distances from cycle's clockwise or lower point and anticlockwise (done)
		clp = cl[i];
		aclp = acl[i];
		
		for(int j=0;j<all_cycles[i].size(); j++){
			// for cl
			if(j==clp) temp_val_cl = 0;
			else if(j > clp){
				temp_val_cl = min(forwards[j]-forwards[clp], forwards[clp]+backwards[j]);
			}
			else if(j < clp){
				temp_val_cl = min(forwards[clp]-forwards[j], forwards[j]+backwards[clp]);
			}
			cl_intercycledistances[i].pb(temp_val_cl);
			
			// for acl
			if(j==aclp) temp_val_acl = 0;
			else if(j > aclp){
				temp_val_acl = min(forwards[j]-forwards[aclp], forwards[aclp]+backwards[j]);
			}
			else if(j < aclp){
				temp_val_acl = min(forwards[aclp]-forwards[j], forwards[j]+backwards[aclp]);
			}
			acl_intercycledistances[i].pb(temp_val_acl);
		}
	}
	
	cl_gcdist[0] = 0;
	ll tmp_gcl = 0;
	for(int i=1;i<n;i++){
		cl_gcdist[i] = tmp_gcl + cl_gcdist[i-1] + gc[i-1];
		tmp_gcl = acl_intercycledistances[i][cl[i]];
	}
	
	acl_gcdist[0] = 0;
	ll tmp_agcl = 0;
	for(int i=n-1;i>=1;i--){
		acl_gcdist[i] = tmp_agcl + acl_gcdist[(i+1)%n] + gc[i];
		tmp_agcl = cl_intercycledistances[i][acl[i]];
	}
}
 
void please_please_please_work(){
	int n = rin(), q = rin();
	
	vector<int> all_cycles[n];
	for(int i=0;i<n;i++){
		int ai = rin();
		for(int j = 0;j<ai;j++) all_cycles[i].pb(rin());
	}
	
	int cl[n], acl[n], gc[n], u, v, w;
	
	for(int i=0;i<n;i++){
		u = rin()-1, v = rin()-1, w = rin();
		cl[i] = u, acl[(i+1)%n] = v, gc[i] = w;
	}
	
	// preprocess O(n) (done)
	vector<ll> cl_intercycledistances[n];	// clockwise distance in each cycles from cycle's clockwise entry point 
	vector<ll> acl_intercycledistances[n];	// anti-clockwise distance in each cycles from cycle's anti-clockwise entry point
	ll cl_gcdist[n]; 						// clockwise distance from 0 to rest cycles 
	ll acl_gcdist[n];						// anti-clockwise distance from 0 to rest cycles
	preprocess(all_cycles, cl, acl, gc, n, cl_intercycledistances, acl_intercycledistances, cl_gcdist, acl_gcdist);
	
	// process queries in O(1)
	int x, y, c1, c2;
	
	while(q--){
		x = rin()-1, c1 = rin()-1, y = rin()-1, c2 = rin()-1;
		ll cl_dist = 0L, acl_dist = 0L;
		
		// ----- this line may cause issues ---- //
		if(c1>c2) swap(c1, c2), swap(x,y);
		
		if(c1==0){
			// special way (let's solve this first for c=1)
			cl_dist = cl_intercycledistances[c1][x] + cl_gcdist[c2] + acl_intercycledistances[c2][y];
			acl_dist = acl_intercycledistances[c1][x] + acl_gcdist[c2] + cl_intercycledistances[c2][y];
		}
		else{
			cl_dist = cl_gcdist[c2] + acl_intercycledistances[c2][y] - cl_gcdist[c1] - acl_intercycledistances[c1][cl[c1]] + cl_intercycledistances[c1][x];
			acl_dist = acl_gcdist[c2] + cl_intercycledistances[c2][y] + acl_intercycledistances[0][cl[0]] + cl_gcdist[c1] + acl_intercycledistances[c1][x];
		}
		
		// print ans
		printf("%lld\n", min(cl_dist, acl_dist));
	}
}
 
int main(){
	int T = rin();
	
	while(T--){
		please_please_please_work();
	}
	
	return 0;
} 
