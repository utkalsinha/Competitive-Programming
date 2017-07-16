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
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int main(){
	int N, Q, i,t, minv = 1000000001, maxv = 0;
	N = rin();
	Q = rin();
	
	for(i=0;i<N;i++){
		t = rin();
		if(t > maxv) maxv = t;
		if(t < minv) minv = t;
	}
	
	for(i=0;i<Q;i++){
		t = rin();
		if(t>=minv && t<=maxv) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
 
