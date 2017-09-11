/*
  Problem 	: Codechef -September Challenge (https://www.codechef.com/SEPT17/problems/CHEFSUM)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <stdio.h>
#include <limits.h>
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
 
typedef long long ll;
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int main(){
	int T = rin(), n, ai;
	while(T--){
		n = rin();
		ll a[n], psum[n], ssum[n], mv;
		mv = LLONG_MAX;
		for(int i=0;i<n;i++) a[i] = rin();
		psum[0] = a[0];
		ssum[n-1] = a[n-1];
		for(int i=1;i<n;i++) psum[i] = psum[i-1] + a[i], ssum[n-1-i] = ssum[n-1-i + 1] + a[n-1-i];
		for(int i=0;i<n;i++) if(psum[i] + ssum[i] < mv) mv = psum[i] + ssum[i], ai = i;
		
		printf("%d\n", ai+1);
	}
	return 0;
}
