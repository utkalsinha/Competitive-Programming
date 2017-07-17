/*
  Problem	:
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX  100001
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

void solve(){
	char str[MAX];
	scanf("%s",str);
	int len = strlen(str);
	bool found = false;
	bool already_found = false;
	FOR(i,len){
		if(str[i] == '1'){
			if(already_found == true){
				already_found = false;
				found = false;
				break;
			} else{
				found = true;
			}

		} else {
			if(found == true){
				already_found = true;
			}
		}
	}
	if(found) printf("YES\n");
	else printf("NO\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}



