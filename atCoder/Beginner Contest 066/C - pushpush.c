/*
  Problem 	: C - pushpush - AtCoder - http://abc066.contest.atcoder.jp/tasks/arc077_a
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[n],ans[n];
	for(i =  0;i<n;i++) scanf("%d",&a[i]);
	for(i = n-1,j = 0;i>=0;i -= 2,j++) ans[j] = a[i];
	if(i== -1) i = 0;
	else if(i == -2 || i== 0) i = 1;
	for(;i<n;i += 2,j++) ans[j] = a[i];
	
	for(i = 0;i<n;i++)printf("%d ",ans[i]);
	
	return 0;
}

