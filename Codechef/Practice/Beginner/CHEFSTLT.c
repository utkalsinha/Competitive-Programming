/*
  Problem	:	CodeChef -Practice (CHEFSTLT - https://www.codechef.com/problems/CHEFSTLT)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>
#define MAX 101

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char s1[MAX], s2[MAX];
		scanf("%s",s1), scanf("%s",s2);
		int len = strlen(s1), qcount = 0, ans = 0, i;
		for(i = 0;i<len;i++){
			if(s1[i] == '?' || s2[i] == '?')qcount++;
			else if(s1[i] != s2[i])ans++;
		}
		printf("%d %d\n",ans,ans+qcount);
	}
	return 0;
}
