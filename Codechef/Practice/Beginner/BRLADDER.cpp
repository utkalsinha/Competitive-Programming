/*
  Problem	:	Codechef - Practice (BRLADDER)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 7
typedef long long int BIG;

void solve(){
	BIG a,b;
	scanf("%lld %lld",&a,&b);
	int diff = abs(a-b);
	if(diff >2) printf("NO\n");
	else{
		if(diff == 2) printf("YES\n");
		else {
			if((a&1) == 0){
				if(b == a-1) printf("YES\n");
				else printf("NO\n");
			}
			else{
				if(a == b-1) printf("YES\n");
				else printf("NO\n");
			}
		}
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



