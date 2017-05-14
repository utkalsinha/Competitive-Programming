/*
  Problem	:
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX 200001
typedef long long int BIG;

int main(){
	BIG n,k,temp, lowest = LLONG_MAX, highest = LLONG_MIN;
	scanf("%lld %lld",&n,&k);
	int houses[MAX];
	memset(houses,0,sizeof(houses));
	FOR(i,n){
		scanf("%lld",&temp);
		houses[temp] = 1;
		if(lowest > temp) lowest = temp;
		if(highest < temp) highest = temp;
	}
	BIG ans = 0,l = lowest, r = highest;
	bool flag = true;
	while(l<=r){
		flag = true;
		for(BIG i = l+k;i>=l;i--){
			if(houses[i] == 1){
				ans++;
				flag = false;
				// get next l
				for(l = i+k+1;l<=r;l++)if(houses[l] == 1) break;
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}



