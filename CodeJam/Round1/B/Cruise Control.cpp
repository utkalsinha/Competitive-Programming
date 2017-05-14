/*
  Problem	:	CodeJam 2017 - Round1B(a)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

void getans(){
	ll D,N;
	scanf("%lld %lld",&D,&N);
	ll tempk,temps;
	double maxhTime = LLONG_MIN, hTime;
	FOR(i,N){
		scanf("%lld %lld",&tempk,&temps);
		hTime = ((D-tempk)*1.0)/temps;
		if(hTime > maxhTime) {
			maxhTime = hTime;
		}
	}
	double ans = D/maxhTime;
	printf("%0.6lf\n",ans);
}

int main(){
	int T;
	scanf("%d", &T);
	FOR(t, T) {
		printf("Case #%d: ", t + 1);
		getans();
	}
	return 0;
}
