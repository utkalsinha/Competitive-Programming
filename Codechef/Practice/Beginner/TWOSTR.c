/*
  Problem 	: Codechef - Beginner - TWOSTR - https://www.codechef.com/problems/TWOSTR
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	int T,i,f;
	char x[11],y[11];
	scanf("%d",&T);
	while(T--){
		f = 0;
		scanf("%s",x);
		scanf("%s",y);
		for(i =0;i<strlen(x);i++){
			if(x[i] !='?' && y[i] != '?' && x[i] != y[i]){
				f = 1;
				break;
			}
		}
		if(f) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

