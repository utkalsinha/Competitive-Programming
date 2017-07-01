/*
  Problem 	: Codechef - Beginner - TRISQ - https://www.codechef.com/problems/TRISQ
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int T,b,n,ans = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&b);
		n = b/2;
		printf("%d\n",(n*(n-1))/2);
	}
	
	return 0;
}

