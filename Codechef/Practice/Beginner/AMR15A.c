/*
  Problem 	: Codechef - Beginner - AMR15A - https://www.codechef.com/problems/AMR15A
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	int n,o = 0,e = 0,t;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		if(t&1)o++;
		else e++;
	}
	if(e>o) printf("READY FOR BATTLE\n");
	else printf("NOT READY\n");
	
	return 0;
}

