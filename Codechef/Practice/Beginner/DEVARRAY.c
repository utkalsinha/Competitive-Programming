/*
  Problem 	: codechef - Practice - DEVARRAY - https://www.codechef.com/problems/DEVARRAY
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif

inline void rin(int &x){ register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }

int main(){
	int N, Q, i,t, minv = 1000000001, maxv = 0;
	rin(N);
	rin(Q);
	
	for(i=0;i<N;i++){
		rin(t);
		if(t > maxv) maxv = t;
		if(t < minv) minv = t;
	}
	
	for(i=0;i<Q;i++){
		rin(t);
		if(t>=minv && t<=maxv) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}

