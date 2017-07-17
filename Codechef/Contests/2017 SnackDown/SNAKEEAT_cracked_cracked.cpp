/*
  Problem	:	SnackDown 2017 - SNAKEEAT (https://www.codechef.com/SNCKQL17/problems/SNAKEEAT)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
typedef long int BIG;

inline void scanint(BIG &x)
{
	register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}

// use Scan_f(&<variable name>)
//inline void Scan_f(BIG *a){char c = 0; while(c<33) c = getc(stdin); *a =0; while(c>33){ *a = (*a)*10+c-'0'; c = getc(stdin);}} 

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
		scanint(n); scanint(q);
		//Scan_f(&n), Scan_f(&q);
		BIG L[n],k, ans, diff;
		//for(i = 0;i<n;i++) Scan_f(&L[i]);
		for(i = 0;i<n;i++) scanint(L[i]);
		sort(L,L+n);
		while(q--){
			//scanf("%lld",&k);
			//Scan_f(&k);
			scanint(k);
			ans = 0;
			i = 0, j= n-1;
			j = getKLessIndex(L,0,n-1,k);
			// case 1 (all values are >= K). In which case j = 0
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
			printf("%ld\n",ans);
		}
	}
	return 0;
}



