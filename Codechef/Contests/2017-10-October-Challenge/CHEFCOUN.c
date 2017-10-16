/*
  Problem 	: Oct17 - long challlenge (https://www.codechef.com/OCT17/problems/CHEFCOUN)
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
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int main(){
	int T = rin();
	
	while(T--){
		int n = rin(), finalvals[n], init = 10000, index;
		for(index = 0; index<42000; index++) {
			finalvals[index] = init, init = init + 3160;
			if(init > 100000) {
				init = 100000;
			}
		}
		for(index = 42000; index<90000; index++){
			finalvals[index] = init, init = init - 52;
			if(init<1){
				init = 1;
			}
		}
		for(; index<n; index++) finalvals[index] = 1;
		// print o/p
		for(int i=0; i<n;i++) printf("%d ", finalvals[i]); printf("\n");
	}
	
	return 0;
} 
