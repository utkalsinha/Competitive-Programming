/*
  Problem	:	Codechef - Practice (PPSUM - https://www.codechef.com/problems/PPSUM)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

 #include <stdio.h>
 
 int main(){
 	int t,d,n;
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d %d",&d,&n);
 		while(d--) n = n*(n+1)>>1;
		printf("%d\n",n);
	 }
 	return 0;
 }
