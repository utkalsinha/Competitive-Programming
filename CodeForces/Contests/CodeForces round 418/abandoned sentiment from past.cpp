/*
  Problem : Codeforces - abandoned sentiment from past - http://codeforces.com/contest/814/problem/A
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

inline void rd_int(int &x){ register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }

int main(){

	int n,k,i;
	rd_int(n),rd_int(k);
	int a[n], b[k];
	for(i = 0;i<n;i++) rd_int(a[i]);
	for(i = 0;i<k;i++) rd_int(b[i]);
	sort(b,b+k);
	for(int j = 0, bj = k-1;j<n;j++){
		if(a[j] == 0){
			a[j] = b[bj];
			bj--;
		}
	}
	int prev = a[0];
	bool flag = false;
	for(i = 1;i<n;i++){
		if(a[i] <= a[i-1]) flag = true;
	}
	flag? printf("Yes\n"):printf("No\n");

	return 0;
}

