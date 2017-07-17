/*
  Problem 	: Codechef - July Challenge - 2017 - CALC - https://www.codechef.com/JULY17/problems/CALC
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif

typedef long long ll;

int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }

int main(){
	int T;
	T = rin();
	ll n,b,ans,bpc,a;
	while(T--){
		n = rinl(), b = rinl();
		if(b>=n) ans = 0;
		else {
			bpc = n/b;
			a = bpc/2 + bpc%2;
			ans = a*(n-a*b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

