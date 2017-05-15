/*
  Problem	:	Codechef - Practice (CIELRCPT - https://www.codechef.com/problems/CIELRCPT)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int n,p,ans;
	scanf("%d",&n);
	while(n--){
		ans = 0;
		scanf("%d",&p);
		if(p>2048) ans = p/2048, p = p%2048;
		while(p){
			
			if((p&1)==1) ans++;
			p = p>>1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
