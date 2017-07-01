/*
  Problem 	:	Codeforces - #421 - 
  Author 	: 	Utkal Sinha
  Contact 	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,x=1,y=2,z=3;
	scanf("%d %d",&n,&a);
	float ea,na,rem,k,prevna;
	ea = ((n-2)*180*1.0)/n;
	prevna = ea;
	rem = n-3;
	for(int i =4,k=rem;i<=n;i++,k--){
		na = k*(ea/(rem+1))*1.0;
		if(na<(a*1.0)) {
			if(abs(a - na)< abs(a-prevna)) z = i;
			break;	
		}
		else {
			z = i;
			prevna = na;	
		}
	}
	
	printf("%d %d %d\n",x,y,z);
	
	return 0;
}
 
