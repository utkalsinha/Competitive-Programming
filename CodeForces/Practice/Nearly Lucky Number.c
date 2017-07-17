/*
  Problem 	: Codeforces - Practice - Nearly Lucky Number - http://codeforces.com/problemset/problem/110/A
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>

int main(){
	long long int n;
	scanf("%I64d",&n);
	
	int count = 0,t;
	
	while(n){
		t = n%10;
		if(t==4 || t==7) count++;
		n /=10;
	}
	if(count==4 || count==7) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}

