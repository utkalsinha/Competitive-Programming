/*
  Problem : Hackerrank - Week of Code 33 - Twin Arrays - https://www.hackerrank.com/contests/w33/challenges/twin-arrays
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

// other useful macros
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define hash unordered_map
#define PI 3.14159265358979323846264338327950288 // In c++, could also use M_PI from the math.h library. In general, const double PI = 2 * acos(0.0);

inline void rd_int(int &x){ register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }

bool comparePairs(pair<int,int>& lhs, pair<int,int>& rhs) { return lhs.first < rhs.first; }

int main(){
	int n,t,ans;
	rd_int(n);
	vector<pair<int,int>> a,b;
	vector<pair<int,int>>::iterator it,it1, it2;
	for(int i = 0;i<n;i++) {
		rd_int(t);
		a.pb(mp(t,i));
	}
	for(int i = 0;i<n;i++) {
		rd_int(t);
		b.pb(mp(t,i));
	}
	sort(a.begin(),a.end(), comparePairs);
	sort(b.begin(),b.end(), comparePairs);
	
	it1 = a.begin();
	it2 = b.begin();
	int t1,t2,t3,t4;
	if(it1->second == it2->second) {
		t1 = (++it1)->first;
		t2 = (it2)->first;
		t3 = (--it1)->first;
		t4 = (++it2)->first;
		
		ans = min(t1+t2, t3+t4);
	}
	else ans = it1->first + it2->first;
	
	printf("%d\n",ans);
	
	return 0;
}
