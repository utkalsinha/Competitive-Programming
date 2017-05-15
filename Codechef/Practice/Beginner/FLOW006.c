/*
  Problem	:	Codechef - Practice (FLOW006 - https://www.codechef.com/problems/FLOW006)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int t,n,ans;
	scanf("%d",&t);
	while(t--){
		ans = 0;
		scanf("%d",&n);
		while(n){
			ans += n%10;
			n /= 10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
