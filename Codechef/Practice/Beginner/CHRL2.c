/*
  Problem : Codechef - Practice - CHRL2 - https://www.codechef.com/problems/CHRL2
  Author : Utkal Sinha
  Contact : info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

#define MAXV 100000

int main(){
	char str[MAXV];
	scanf("%s",str);
	int ans = 0,i,count;
	int n = strlen(str);
	i = 0;
	while(i<n){
		count = 0;
		while(str[i] != 'C' && i<n)i++;
		if(i<n)count++;
		while(str[i] != 'H' && i<n)i++;
		if(i<n)count++;
		while(str[i] != 'E' && i<n)i++;
		if(i<n)count++;
		while(str[i] != 'F' && i<n)i++;
		if(i<n)count++;
		if(count == 4)ans++;
	}
	
	printf("%d\n",ans);
	
	return 0;
}
