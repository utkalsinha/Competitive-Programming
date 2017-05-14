/*
  Problem	:	Codechef - Practice (DWNLD: https://www.codechef.com/problems/DWNLD)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <stdio.h>
 
int main(){
	int T;
	scanf("%d",&T);
	while(T){
		int n, k, ti, di, diff, f=0, ans = 0, i;
		scanf("%d %d",&n,&k);
		for(i = 0;i<n;i++){
			scanf("%d %d",&ti, &di);
			if(f == 0){
				k -= ti;
				if(k <= 0){
					f = 1;
					ans += -1*k*di;
				}
			}
			else ans += ti*di;
		}
		printf("%d\n",ans);
		T--;
	}
	return 0;
}
