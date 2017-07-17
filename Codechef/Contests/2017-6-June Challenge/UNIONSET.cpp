/*
  Problem : Codechef - UNIONSET (https://www.codechef.com/JUNE17/problems/UNIONSET)
  Author : Utkal Sinha
  Contact : info@utkalsinha.com
*/
 
#include <bits/stdc++.h>
 
using namespace std;
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
 
// other useful macros
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define hash unordered_map
#define PI 3.14159265358979323846264338327950288 // In c++, could also use M_PI from the math.h library. In general, const double PI = 2 * acos(0.0);
 
//Code specific macros
#define MAXV 2501
// when using c++ (call it as rd_int(x))
 
inline void rd_int(int &x){ register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }
 
void solve(){
	int n,k,i,j,s,temp,z;
	rd_int(n), rd_int(k);
	
	int row_element_count[n];
	memset(row_element_count, 0, sizeof(row_element_count));
	
	int binary_mask[n][k];
	memset(binary_mask, 0, sizeof(binary_mask));
	
	vector<unordered_set<int>> allSets;
	for(i = 0;i<n;i++){
		rd_int(row_element_count[i]);
		unordered_set<int> t;
		for(j = 0;j<row_element_count[i];j++){
			rd_int(temp);
			binary_mask[i][temp-1] = 1;
			t.insert(temp);
		}
		allSets.pb(t);
	}
	int ans = 0;
	int temp_count;
	unordered_set<int>::iterator it1, it2;
	for(i = 0;i<n-1;i++){
		for(j = i+1;j<n;j++){
			temp_count = row_element_count[i];
			it2 = allSets[j].begin();
			while(it2 != allSets[j].end()) {
				if(!binary_mask[i][*it2-1]) temp_count++;
				++it2;
			}
			if(temp_count == k) ans++;
		}
	}
	printf("%d\n",ans);
}
 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
