/*
  Problem	:	CodeChef -Practice (CATSDOGS)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int BIG;

void solve(){
	BIG c,d,l;
	bool correct = false;
	scanf("%lld %lld %lld",&c,&d,&l);
	if(l % 4 != 0 || l < d<<2 || l>(c+d)<<2){
		printf("no\n");
	}
	else {
		if(c <= (l>>2) + d) printf("yes\n");
		else printf("no\n");
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



