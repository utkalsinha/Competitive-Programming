#include <stdio.h>

int gcd(int a, int b){
	while(a&&b) (a>b)?a%=b:b%=a;
	return a+b;
}

int main(){
	int x = gcd(2,5);
	printf("%d\n",x);
	return 0;
}
