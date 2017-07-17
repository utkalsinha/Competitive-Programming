/*
  Problem	:	SnackDown 2017 - SNAKEEAT (https://www.codechef.com/SNCKQL17/problems/SNAKEEAT)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int BIG;
#define gc getchar_unlocked

inline void scanint(BIG &x)
{
	register int c = getchar();
    x = 0;
    for(;(c<48 || c>57);c = getchar());
    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
}

BIG getKLessIndex(BIG L[], BIG l, BIG r, BIG K)
{
	BIG m;
	m = l + (r-l)/2;
	while (l <= r) {
	    if (m > 0 && L[m] >= K && L[m-1] < K) 
	        return m;
	    if (L[m] >= K)
	    	r = m - 1;
	    else
	        l = m + 1;
		m = l + (r-l)/2; 
	}
	return m;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		BIG n,q,i,j;
		scanf("%lld",&n),scanf("%lld",&q);
		//scanint(n),scanint(q);
		BIG L[n],K[q],k, ans, diff;
		for(i = 0;i<n;i++) scanf("%lld",&L[i]);
		for(i = 0;i<q;i++) scanf("%lld",&K[i]);
		sort(L,L+n);
		for(i = 0;i<q;i++){
			printf("q = %lld\n",q);
			k = K[i];
			ans = 0;
			i = 0, j= n-1;
			j = getKLessIndex(L,0,n-1,k);
			if(j == 0) ans = n;
			else{
				ans = n - j;
				j--;
				while(i<=j){
					diff = (k-L[j]);
					if(diff > (j-i)) break;
					else {
						ans++;
						i += diff;
					}
					j--;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}



