/*
  Problem 	: Oct17 - long challlenge (https://www.codechef.com/OCT17/problems/MEX)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <stdio.h>
#include <string.h>
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define MAXV 200002
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int val[MAXV];
 
int main(){
	int T = rin();
	
	while(T--){
		int n = rin(), k = rin(), resv = 0;
		memset(val, 0, sizeof(val));
		
		for(int i=0;i<n;i++){
			val[rin()] = 2;
		}
		
		for(int i=0;i<MAXV;i++){
			if(val[i]==0){
				if(k)k--;
				else {
					resv = i;
					break;
				}
			}
		}
		printf("%d\n", resv);
	}
	
	return 0;
} 
