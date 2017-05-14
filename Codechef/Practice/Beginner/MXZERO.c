/*
  Problem	:	Codechef - Practice (MXZERO: https://www.codechef.com/problems/MXZERO)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <stdio.h>
 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,o = 0,t,i;
		scanf("%d",&n);
		for(i = 0;i<n;i++) {
			scanf("%d",&t);
			if(t)o++;
		}
		(o&1)==0?printf("%d\n",n-o):printf("%d\n",o);
	}
	return 0;
}
