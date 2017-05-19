/*
  Problem	:	Codechef - CHEFROUT - https://www.codechef.com/MAY17/problems/CHEFROUT
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char str[100000];
		scanf("%s",str);
		int l = strlen(str);
		int z = 0;
		bool f = false;
		for(int i = 0;i<l;i++){
			if(str[i] == 'C'){
				if(z <= 1){
					z = 1;
				}
				else{
					f = true;
				}
			}
			else if(str[i] == 'E'){
				if(z <=2){
					z = 2;
				}
				else{
					f = true;
				}
			}
			else if(str[i] == 'S'){
				if(z<=3){
					z = 3;
				}
				else{
					f = true;
				}
			}
		}
		if(f == true){
			printf("no\n");
		}
		else{
			printf("yes\n");
		}
	}
	return 0;
}



