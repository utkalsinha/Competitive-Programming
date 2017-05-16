/*
  Problem	:	CodeChef -Practice (CFRTEST - https://www.codechef.com/problems/CFRTEST)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int T,n,ans,temp;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		unordered_map<int, int> hmap;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&temp);
			if(hmap.find(temp) == hmap.end()){
				hmap[temp] = 1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
