/*
  Problem	:	Codechef - LOC171
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <iostream>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long int BIG;

void solve(){
	int N;
	scanf("%d",&N);
	BIG temph;
	BIG count = 0, prev = 0;
	BIG ans = 0;
	FOR(i,N){
		scanf("%llu",&temph);
		if(prev == temph) count++;
		else{
			prev = temph;
			ans += (count*(count+1))>>1;
			count = 1;
		}
	}
	ans += (count*(count+1))>>1;
	printf("%llu\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}

