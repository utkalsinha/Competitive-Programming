/*
  Problem 	: Codechef - July Challenge - 2017 - CHEFSIGN - https://www.codechef.com/JULY17/problems/CHEFSIGN
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

#define MAXV 100005

typedef long long ll;

int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }

int main(){
	int T,i,len,maxv, minv, cur,count;
	T = rin();
	char str[MAXV];
	while(T--){
		scanf("%s",str);
		len = strlen(str);
		maxv = 1;
		cur = 1;
		count = 0;
		for(i = 0;i<len;i++){
			if(str[i]=='<'){
				cur++;
				count = 0;
				if(cur>maxv) maxv = cur;
			} else if(str[i]=='>'){
				count++;
				cur = 1;
				if(count>=maxv) maxv++;
			}
		}
		printf("%d\n",maxv);
		
	}
	return 0;
}

