/*
  Problem	:
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

void solve(){
	int N;
	int buckets[6] = {0};
	scanf("%d",&N);
	int over;
	float t;
	for(int i = 0;i<N;i++){
		scanf("%f",&t);
		over = (int)t;
		switch(over){
			case 0 ... 79:
				if(buckets[0] <2) buckets[0]++;
				break;
			case 80 ... 159:
				if(buckets[1] <2) buckets[1]++;
				break;
			case 160 ... 239:
				if(buckets[2] <2) buckets[2]++;
				break;
			case 240 ... 319:
				if(buckets[3] <2) buckets[3]++;
				break;
			case 320 ... 399:
				if(buckets[4] <2) buckets[4]++;
				break;
			case 400 ... 449:
				if(buckets[5] <2) buckets[5]++;
				break;				
		}
	}
	int ans = buckets[0]+buckets[1]+buckets[2]+buckets[3]+buckets[4]+buckets[5];
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}

