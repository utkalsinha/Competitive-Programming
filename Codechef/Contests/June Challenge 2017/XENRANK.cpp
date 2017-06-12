/*
  Problem	:	Codechef - XENRANK - https://www.codechef.com/JUNE17/problems/XENRANK
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <stdio.h>
 
int main(){
	int T;
	long long u,v,n;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&u,&v);
		n = u+v;
		n = (n*(n+1))>>1;
		n += u + 1;
		printf("%lld\n",n);
	}
	return 0;
} 
