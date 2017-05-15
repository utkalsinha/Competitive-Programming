/*
  Problem	:	Codechef - Practice (INTEST - https://www.codechef.com/problems/INTEST)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
typedef long long int ll;

int main(){
	ll n,k,t,ans = 0;
	scanf("%lld %lld",&n,&k);
	while(n--){
		scanf("%lld",&t);
		if(t%k == 0) ans++;
	}
	printf("%lld\n",ans);
	return 0;	
}
