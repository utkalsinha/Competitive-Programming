/*
  Problem	:	Codechef - MXMEDIAN - https://www.codechef.com/MAY17/problems/MXMEDIAN
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		int len = 2*N;
		int arr[len];
		FOR(i,len) scanf("%d",&arr[i]);
		sort(arr,arr+len);
		int medi = N+N/2;
		printf("%d\n",arr[medi]);
		for(int i = 0,j = N;i<N;i++,j++) printf("%d %d ",arr[i],arr[j]);
		printf("\n");
	}
	return 0;
}



