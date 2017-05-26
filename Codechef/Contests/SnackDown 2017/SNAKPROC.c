/*
  Problem	:	SnackDown 2017 - SNAKPROC (https://www.codechef.com/SNCKQL17/problems/SNAKPROC)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
#define MAX 501

int main(){
	int T, n, i, obeyed;
	scanf("%d",&T);
	while(T--){
		char str[MAX];
		obeyed = 1;
		scanf("%d",&n);
		scanf("%s",str);
		for(i = 0;i<n;i++){
			if(!(str[i] =='.')){
				if(str[i] == 'H'){
					if(obeyed == 0) break;
					else obeyed = 0;
				}
				else{
					if(obeyed == 1) {
						obeyed = 0;
						break;
					}
					else obeyed = 1;
				}
			}
		}
		(obeyed)?printf("Valid\n"):printf("Invalid\n");
	}
	return 0;
}



