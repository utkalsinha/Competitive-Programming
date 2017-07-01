/*
  Problem 	: B - ss - AtCoder - http://abc066.contest.atcoder.jp/tasks/abc066_b
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <string.h>

int main(){
	char str[201];
	scanf("%s",str);
	int ans= 0,m,i,j;
	int len = strlen(str)-1;
	
	while(len >= 1){
		m = len/2;
		for(i = 0,j=m;i<m;i++,j++){
			if(str[i]!=str[j]) {
				ans = 0;
				break;
			}
			else ans += 2;
		}
		if(i==m)break;
		len = len - 1;
	}
	printf("%d\n",ans);
	
	return 0;
}

