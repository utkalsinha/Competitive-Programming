/*
  Problem 	:	Codeforces Round #422 (Div. 2) - http://codeforces.com/contest/822/problem/A
  Author 	: 	Utkal Sinha
  Contact 	: 	info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	long long int a,b,n,ans = 1,i;
	scanf("%I64d %I64d",&a,&b);
	if(a<b)n = a;
	else n = b;
	for(i = 2;i<=n;i++) ans *= i;
	printf("%I64d\n",ans);

	return 0;
}

