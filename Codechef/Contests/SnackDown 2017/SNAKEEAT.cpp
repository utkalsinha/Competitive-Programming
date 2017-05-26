/*
  Problem	:	SnackDown 2017 - SNAKEEAT (https://www.codechef.com/SNCKQL17/problems/SNAKEEAT)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int BIG;

void solve(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	BIG L[n],k, ans, diff;
	for(i = 0;i<n;i++) scanf("%lld",&L[i]);
	stable_sort(L,L+n);
	while(q--){
		scanf("%lld",&k);
		ans = 0;
		i = 0, j= n-1;
		while(i<=j){
			if(L[j] >=k)ans++;
			else{
				diff = (k-L[j]);
				if(diff > (j-i)) break;
				else {
					ans++;
					i += diff;
				}
			}
			j--;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}



