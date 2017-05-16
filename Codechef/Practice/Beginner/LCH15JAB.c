/*
  Problem	:	CodeChef -Practice (LCH15JAB - https://www.codechef.com/problems/LCH15JAB)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
#define MAX 51

int main(){
	int T;
	scanf("%d",&T),getchar();
	int sumv,f,i;
	char c;
	while(T--){
		int ccount[26] = {0};
		sumv = 0, f = 0;
		while((c = getchar()) != '\n') {
			ccount[c-'a']++;
			sumv++;
		}
		for(i = 0;i<26;i++) if(ccount[i] && (ccount[i]<<1) == sumv) f = 1;
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
