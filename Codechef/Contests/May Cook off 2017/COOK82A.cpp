/*
  Problem	:	May Cook-Off 2017 - COOK82A (https://www.codechef.com/COOK82/problems/COOK82A)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	int t,bw_check, rmw_check_lose, teams_count;
	scanf("%d",&T);
	while(T--){
		unordered_map<char, int> mymap;
		string str;
		teams_count = 4;
		while(teams_count--){
			cin >> str;
			scanf("%d",&t);
			mymap[str[0]] = t;
		}
		rmw_check_lose = ((mymap['R'] < mymap['M'])?1:0);
		bw_check = ((mymap['B'] > mymap['E'])?1:0);
		if(rmw_check_lose && bw_check) printf("Barcelona\n");
		else printf("RealMadrid\n");
	}
	return 0;
}



