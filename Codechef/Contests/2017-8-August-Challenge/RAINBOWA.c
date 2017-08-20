/*
  Problem 	: Codechef August - 2017- https://www.codechef.com/AUG17/problems/RAINBOWA
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
	int T= rin(), n,i, prev, flag;
	int num[100];
	while(T--){
		flag = 1;
		prev = 0;
		n = rin();
		for(i=0;i<n;i++) num[i] = rin();
		
		for(i=0;i<(n>>1);i++) {
			if(num[i] != num[n-i-1] || (num[i]-prev)>1){
				flag = 0;
				break;
			}
			prev = num[i];
		}
		
		if(!flag) printf("no\n");
		else{
			if(n&1){
				if(num[i]-prev>1 || num[i] != 7) printf("no\n");
				else printf("yes\n");
			} else {
				if(num[i] != 7) printf("no\n");
				else printf("yes\n");
			}
		}
	}
	return 0;
}
