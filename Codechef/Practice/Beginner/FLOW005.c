/*
  Problem 	: Codechef - Beginner - FLOW005 - https://www.codechef.com/problems/FLOW005
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int T,n,ans;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%d",&n);
		ans += n/100;
		n %= 100;
		ans += n/50;
		n %= 50;
		ans += n/10;
		n %= 10;
		ans += n/5;
		n %= 5;
		ans += n/2;
		n %= 2;
		ans += n/1;
		printf("%d\n",ans);
	}
	
	return 0;
}

