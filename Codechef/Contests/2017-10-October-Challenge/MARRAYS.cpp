/*
  Problem 	: Oct17 long challenge (https://www.codechef.com/OCT17/problems/MARRAYS)
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
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
typedef vector<vector<int>> MAT;
typedef long long ll;
 
void findans(){
	int n = rin(), m, tmpmax, tmpmin, tmpv;
	ll res = 0L;
	
	MAT dishes;
	int maxmin[n][2]; // (n-1)th dish, maxmin[][0] -> min, maxmin[][1] -> max
	
	for(int i=0; i<n; i++){
		vector<int> tmp;
		m = rin();
		tmpmax = INT_MIN, tmpmin = INT_MAX;
		for(int j = 0; j<m; j++) {
			tmpv = rin();
			if(tmpmin>tmpv) tmpmin = tmpv, maxmin[i][0] = j;
			if(tmpmax<tmpv) tmpmax = tmpv, maxmin[i][1] = j;
			
			tmp.pb(tmpv);
		}
		dishes.pb(tmp);
	}
	
	// solve
	if(n==1) res = 0; // try with res = 0 as well as not sure.
	else if(n==2){
		int tl = 0;
		tl = max(tl, abs(dishes[0][maxmin[0][1]] - dishes[1][maxmin[1][1]]));
		tl = max(tl, abs(dishes[0][maxmin[0][1]] - dishes[1][maxmin[1][0]]));
		tl = max(tl, abs(dishes[0][maxmin[0][0]] - dishes[1][maxmin[1][1]]));
		tl = max(tl, abs(dishes[0][maxmin[0][0]] - dishes[1][maxmin[1][0]]));
		res = tl;
	}
	else{
		vector<ll> temp, backup; // pair<index, val>
		for(int i=0;i<dishes[n-1].size();i++) backup.pb(0);
		
		for(int i=n-1; i>=1;i--){
			temp.clear();
			for(int j = 0;j<dishes[i-1].size(); j++){
				
				ll lval = 0;
				int fp;
				for(int k = 0;k<backup.size();k++){
					if(k==0) fp = backup.size() - 1;
					else fp = k-1;
					lval = max(lval, 1L*(backup[fp] + 1L*(i)*(abs(dishes[i-1][j]-dishes[i][k]))));
				}
				temp.pb(lval);
			}
			swap(temp, backup);
		}
		
		for(int i=0;i<backup.size();i++){
			res = max(res, backup[i]);
		}		
	}
	
	
	printf("%lld\n", res);
}
 
int main(){
	int T = rin();
	while(T--) findans();
	return 0;
} 
