#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ while(a&&b) (a>b)?a%=b:b%=a; return a+b; }

int pollardRho(int n) {
  if(n%2==0)
    return 2 ;
  srand (time(NULL)) ; 
  int x, y , g=1 , a;
  x = rand() % n + 1 ;
  y = x ;
  a = rand() % n + 1 ;
  while(g==1) {
    x = ((x*x) + a)%n ;  
    y = ((y*y) + a)%n ;
    y = ((y*y) + a)%n ;  
    g = gcd(abs(x - y), n) ;
  }
  return g ;
}




// Main program to check and demo
int main(){
	int n = 49*7;
	printf("one factor of %d is %d\n",n,pollardRho(n));
	return 0;
}