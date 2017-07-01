/*
  Problem 	: Codechef - Beginner - HEADBOB - https://www.codechef.com/problems/HEADBOB
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	int T,len,j,y,n,i;
	char s[1001];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&len);
		scanf("%s",s);
		n=y=i=0;
		for(j =0;j<len;j++){
			if(s[j]=='Y')y=1;
			if(s[j]=='N')n=1;
			if(s[j]=='I')i=1;
		}
		if(i) printf("INDIAN\n");	
		else if(y) printf("NOT INDIAN\n");
		else printf("NOT SURE\n");
	}
	
	return 0;
}

