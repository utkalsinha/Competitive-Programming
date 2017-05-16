/*
  Problem	:	CodeChef -Practice (CFRTEST - https://www.codechef.com/problems/CFRTEST)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
#define MAX 101
int main(){
	int T,n,ans,temp,i;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		int nums[MAX] = {0};
		scanf("%d",&n);
		for(i = 0;i<n;i++){
			scanf("%d",&temp);
			if(nums[temp] == 0){
				nums[temp] = 1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
