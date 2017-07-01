/*
  Problem 	: Codechef - Practice - FLOW007 - https://www.codechef.com/problems/FLOW007
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

void solve(){
	int n;
	scanf("%d",&n);
	while(n%10 == 0) n /=10;
	while(n){
		printf("%d",n%10);
		n = n/10;
	}
	printf("\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	
	return 0;
}
