/*
  Problem	:	Codechef - GOODSET - https://www.codechef.com/JUNE17/problems/GOODSET
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <stdio.h>
#if 1 // change this value to 0 while developing on Windows platform
#define gc getchar_unlocked
#else
#define gc getchar
#endif
 
int rd_int() {
	int flag=0;
	char c = gc();
	if(c=='-')flag=1;
	while(c<'0' || c>'9') c = gc();
	int res = 0;
	while(c>='0' && c<='9'){
		res = 10 * res + c - 48;
		c = gc();
	}
	if(!flag)return res;
	else return (-res);
}
 
int main(){
	int T,n,i;
	scanf("%d",&T);
	/*
		The nums array has been generated using the following code and has been hardcoded only for efficiency purposes:
		int n = 100, cur = 4;
		printf("{1,2,4,");
		for(int i = 0;i<97;i++, cur += 3)printf("%d,",cur+3);
		printf("}\n");
	*/
	int nums[] = {1,2,4,7,10,13,16,19,22,25,28,31,34,37,40,43,46,49,52,55,58,61,64,67,70,73,76,79,82,85,88,91,94,97,100,103,106,109,112,115,118,121,124,127,130,133,136,139,142,145,148,151,154,157,160,163,166,169,172,175,178,181,184,187,190,193,196,199,202,205,208,211,214,217,220,223,226,229,232,235,238,241,244,247,250,253,256,259,262,265,268,271,274,277,280,283,286,289,292,295};
	while(T--){
		n = rd_int();
		for(i=0;i<n;i++)printf("%d ",nums[i]);
		printf("\n");
	}
	return 0;
}
