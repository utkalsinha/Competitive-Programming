/*
  Problem	:	SnackDown 2017 - TEMPLELA (https://www.codechef.com/SNCKQL17/problems/TEMPLELA)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,i,j,p = 0,f=1;
		scanf("%d",&n);
		int h[n];
		for(i = 0;i<n;i++) scanf("%d",&h[i]);
		if(((n&1) == 0) || (h[0] != 1)) printf("no\n");
		else{
			for(i=0,j=n-1;i<n/2;i++,j--){
				if((h[i]-p == 1) && (h[i] == h[j])) p = h[i];
				else{
					f = 0;
					break;
				}
			}
			f?printf("yes\n"):printf("no\n");
		}
	}
	return 0;
}



