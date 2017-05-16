/*
  Problem	:	CodeChef -Practice (KTTABLE - https://www.codechef.com/problems/KTTABLE)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
typedef long long ll;
int main(){
	int T,N,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		ll A[N],B[N],ans = 0, prev = 0;
		for(i = 0;i<N;i++) scanf("%lld",&A[i]);
		for(i = 0;i<N;i++) scanf("%lld",&B[i]);
		for(i = 0;i<N;i++) {
			if(A[i]-prev >= B[i])ans++;
			prev = A[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
