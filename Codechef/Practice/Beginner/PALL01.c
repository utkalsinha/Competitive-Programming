/*
  Problem 	: Codechef - Beginner - PALL01 - https://www.codechef.com/problems/PALL01
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	int T,len,i,f;
	char s[10001];
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		f = 0;
		len = strlen(s);
		for(i =0;i<len/2;i++){
			if(s[i] != s[len-i-1]){
				f = 1;
				break;
			}
		}
		if(f)printf("losses\n");
		else printf("wins\n");
	}
	
	return 0;
}

