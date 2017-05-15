/*
  Problem	:	Codechef - Practice (CHEFSTUD - https://www.codechef.com/problems/CHEFSTUD)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>
#define MAX 100001

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char s[MAX],p;
		scanf("%s",s);
		int len = strlen(s), count = 0,i;
		p = s[0];
		for(i = 1;i<len;i++){
			if(p == '<' && s[i] == '>') count++;
			p = s[i];
		}
		printf("%d\n",count);
	}
	return 0;
}
