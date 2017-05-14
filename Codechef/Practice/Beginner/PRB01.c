/*
  Problem	:	Codechef - Practice (PRB01)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
#include <math.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int  n, f=1, i;
		scanf("%d",&n);
		int r = sqrt(n);
		for(i = 2;i<r;i++){
			if(n%i == 0){
				f = 0;
				break;
			}
		}
		f == 0 ? printf("no\n"):printf("yes\n");
	}
	return 0;
}



