/*
  Problem 	: Codechef - September Challenge (https://www.codechef.com/SEPT17/problems/SEACO)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
using namespace std;
 
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define mt make_tuple
#define pb push_back
#define MODV 1000000007
 
typedef long long ll;
typedef tuple<int, int, int, ll> CMDS;
 
int BLOCKSIZE;
 
inline int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
void decomposeT2cms(vector<int> &type2positions, CMDS queries[], ll qb[]){
	
	int type, l, r, i, repeat_c, qbi, cbi, blowerb, bupperb;
	
	for(int p = type2positions.size()-1; p>=0; p--){
		i = type2positions[p];
		
		l = get<1>(queries[i]), r = get<2>(queries[i]);
		repeat_c = get<3>(queries[i])+1;
		
		qbi = i/BLOCKSIZE + (i%BLOCKSIZE==0?-1:0);
		cbi = l/BLOCKSIZE + (l%BLOCKSIZE==0?-1:0);
		
		repeat_c = (repeat_c + qb[qbi]);
		
		
		while(l<=r){
			blowerb = cbi * BLOCKSIZE + 1, bupperb = (cbi + 1) * BLOCKSIZE;
			
			if(l == blowerb){
				if(r>= bupperb) qb[cbi] = (qb[cbi] + repeat_c)%MODV;
				else while(l<=r) get<3>(queries[l]) = (get<3>(queries[l]) + repeat_c)%MODV, l++;
			}
			else while(l <= r && l <= bupperb) get<3>(queries[l]) = (get<3>(queries[l]) + repeat_c)%MODV, l++;
			
			cbi++;
			l = cbi * BLOCKSIZE+1;
		}
	}
}
 
void decomposeT1cms(vector<int> &type1positions, CMDS queries[], ll ans[], ll ansb[], ll qb[]){
	
	int type, l, r, i, repeat_c, cbi, qbi, blowerb, bupperb;
	
	for(int p=0; p < type1positions.size(); p++){
		i = type1positions[p];
		
		l = get<1>(queries[i]), r = get<2>(queries[i]);
		
		qbi = i/BLOCKSIZE + (i%BLOCKSIZE==0?-1:0);
		cbi = l/BLOCKSIZE + (l%BLOCKSIZE==0?-1:0);
		
		repeat_c = (get<3>(queries[i]) + qb[qbi] + 1) % MODV;
 
		while(l<=r){
			blowerb = cbi * BLOCKSIZE + 1, bupperb = (cbi+1) * BLOCKSIZE;
			
			if(l == blowerb){
				if(r>= bupperb) ansb[cbi] = (ansb[cbi] + repeat_c) % MODV;
				else while(l<=r) ans[l] = (ans[l] + repeat_c) % MODV, l++;
			}
			else while(l <= r && l <= bupperb) ans[l] = (ans[l] + repeat_c) % MODV, l++;
			
			cbi++;
			l = cbi * BLOCKSIZE+1;
		}
	}
}
 
void pushd(int n, int nblocks, ll ans[], ll ansb[]){
	ll l=1, r, offset, cbi;
	
	for(int i = 0; i<nblocks ;i++){
		cbi = i;
		offset = ansb[i];
		r = (cbi+1) * BLOCKSIZE;
		while(l<=n && l<=r) printf("%lld ", (ans[l] + offset) % MODV), l++;
	}
	printf("\n");
}
 
int main(){
	int T = rin();
	
	while(T--) {
		int type, l, r, n, m;
		n = rin(), m = rin();
		
		BLOCKSIZE = max((int)sqrt(n), 150);
		int mblocks = m/BLOCKSIZE + (m%BLOCKSIZE==0?0:1);
		int nblocks = n/BLOCKSIZE + (n%BLOCKSIZE==0?0:1);
		ll qb[mblocks] = {0};
		
		ll ans[n+1] = {0};
		ll ansb[nblocks] = {0};
		
		CMDS queries[m+1];
		vector<int> type2positions;
		vector<int> type1positions;
		
		for(int i=1;i<=m;i++){
			type = rin(), l = rin(), r = rin();
			if(type==1) type1positions.pb(i);
			else type2positions.pb(i);
			queries[i] = mt(type,l,r,0);
		}
		
		decomposeT2cms(type2positions, queries, qb);
		decomposeT1cms(type1positions, queries, ans, ansb, qb);
		pushd(n, nblocks, ans, ansb);
	}
	
	return 0;
} 
