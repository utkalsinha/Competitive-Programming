/*
  Problem	:	Codechef - Practice (OMWG - https://www.codechef.com/problems/OMWG)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <stdio.h>

int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		printf("%d\n",2*n*m-n-m);
	}
	return 0;
}
