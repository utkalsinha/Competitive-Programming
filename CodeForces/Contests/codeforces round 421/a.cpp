/*
  Problem 	:	Codeforces - #421 - 
  Author 	: 	Utkal Sinha
  Contact 	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int c,v0,v1,a,l,days,curpageNum,increment;
	scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
	days = 1;
	curpageNum = v0;
	increment = v0;
	
	while(curpageNum < c){
		curpageNum -= l;
		if((increment+a)>=v1) increment = v1;
		else increment = increment + a;
		curpageNum += increment;
		//else curpageNum += increment - l;
		days++;
	}
	printf("%d\n",days);

	return 0;
}

