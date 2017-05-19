/*
  Problem	:	Codechef - UNICOURS - https://www.codechef.com/MAY17/problems/UNICOURS
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long int BIG;

void solve(){
	int n,t;
	scanf("%d",&n);
	int max = INT_MIN;
	FOR(i,n){
		scanf("%d",&t);
		if(max <t) max = t;
	}
	printf("%d\n",n-max);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}



