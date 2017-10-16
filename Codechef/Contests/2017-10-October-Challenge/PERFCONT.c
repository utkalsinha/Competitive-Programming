/*
  Problem 	: Oct17 - long challlenge (https://www.codechef.com/OCT17/problems/PERFCONT)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <stdio.h>
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
		int n = rin(), p = rin(), cakec = 0, hardc = 0, suc = 1;
		int arr[n];
		for(int i=0;i<n;i++) arr[i] = rin();
		for(int i=0;i<n;i++) {
			if(arr[i]>=(p>>1)) {
				cakec++;
				if(cakec>1){
					suc = 0;
					break;
				}
			}
			else if(arr[i]<= p/10){
				hardc++;
				if(hardc>2){
					suc = 0;
					break;
				}
			}
		}
		if(suc && hardc == 2 && cakec == 1) printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
} 
