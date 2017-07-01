/*
  Problem 	: A - ringring - AtCoder - http://abc066.contest.atcoder.jp/tasks/abc066_a
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int a,b,c,ans = 0;
	scanf("%d %d %d",&a,&b,&c);
	if(a<b){
		if(c<b) ans = a+c;
	 	else ans = a+b;
	} else {
		if(a<c) ans = a+b;
		else ans = c+b;
	}
	printf("%d\n",ans);
	return 0;
}

