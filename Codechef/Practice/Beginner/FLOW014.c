/*
  Problem 	: Codechef - Beginner - FLOW014 - https://www.codechef.com/problems/FLOW014
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	int T,a,c,ca,cb,cc;
	float b;
	scanf("%d",&T);
	while(T--){
		ca = cb = cc = 0;
		scanf("%d %f %d",&a,&b,&c);
		if(a>50)ca = 1;
		if(b<0.7)cb = 1;
		if(c>5600) cc = 1;
		if(ca && cb && cc) printf("10\n");
		else if(ca && cb && !cc) printf("9\n");
		else if(!ca && cb && cc) printf("8\n");
		else if(ca && !cb && cc) printf("7\n");
		else if((ca && !cb && !cc)||(!ca && cb && !cc)||(!ca && !cb && cc)) printf("6\n");
		else printf("5\n");
	}
	return 0;
}

