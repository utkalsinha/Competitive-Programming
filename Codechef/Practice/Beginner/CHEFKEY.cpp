/*
  Problem	:	Codechef - Practice (CHEFKEY)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long int BIG;

void solve(){
	int n,m,c,a,b;
	int count = 0;
	scanf("%d %d %d", &n,&m,&c);
	for(int i = 1;i<=c;i++){
		if(c % i == 0){
			a = c/i;
			if((i>=1 && i<=n)&&(a>=1 && a<=m)) count++;
		}
	}
	printf("%d\n",count);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}



