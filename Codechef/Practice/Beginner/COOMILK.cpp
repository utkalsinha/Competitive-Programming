/*
  Problem	:	Codechef - Practice (COOMILK: https://www.codechef.com/problems/COOMILK)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 7
typedef unsigned long long int BIG;

void solve(){
	bool obeyed = true;
	char prev = ' ';
	char ops[MAX];
	int N;
	scanf("%d",&N);
	for(int i  =0;i<N;i++){
		scanf("%s",ops);
		if(ops[0] == 'c' && prev == 'c') obeyed = false;
		prev = ops[0];
	}
	if(ops[0] == 'c') obeyed = false;
	if(!obeyed) printf("NO\n");
	else printf("YES\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}



