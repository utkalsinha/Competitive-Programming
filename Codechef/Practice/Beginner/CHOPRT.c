/*
  Problem 	: Codechef - Beginner - CHOPRT - https://www.codechef.com/problems/CHOPRT
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&b);
		if(a>b)printf(">\n");
		if(a<b)printf("<\n");
		if(a==b)printf("=\n");
	}
	
	return 0;
}

