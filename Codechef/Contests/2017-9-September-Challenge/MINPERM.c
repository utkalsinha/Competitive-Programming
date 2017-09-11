/*
  Problem 	: Codechef -September Challenge (https://www.codechef.com/SEPT17/problems/MINPERM)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <stdio.h>
#include <limits.h>
#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int main(){
	int T = rin(), n;
	while(T--){
		n = rin();
		if(n&1){
			for(int i=0, j = 2;i<((n-3)>>1);i++, j+=2) printf("%d %d ", j, j-1);
			printf("%d %d %d", n-1, n, n-2);
		}
		else for(int i=0, j = 2;i<(n>>1);i++, j += 2) printf("%d %d ", j, j-1);
		printf("\n");
	}
	return 0;
}
