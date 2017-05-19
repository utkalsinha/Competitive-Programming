/*
  Problem	:	Codechef - CHEFSUBA - https://www.codechef.com/MAY17/problems/CHEFSUBA
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <bits/stdc++.h>
using namespace std;
#define MAXS 100001
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
int getmaxones2(int mat[], int n, int k){
	int count = 0, max = -1;
	int fi,li;
	fi = 0;
	int z = 0;
	while(z<k){
		if(mat[z]==1)count++;
		z++;
	}
	if(max < count) max = count;
	for(int i = z;i<n;i++){
		if(mat[fi] == 1){
			count--;
		}
		if(mat[i] == 1){
			count++;
		}
		if(max<count) max = count;
		fi++;
	}
	return max;	
}

int foo(int k, int n){
    while(k < 0) {
        k += n;
    }
    return k % n;
}
int belt[MAXS],temp_belt[MAXS];
char dog[MAXS];	

int main(){
	int N,K,P;
	scanf("%d %d %d",&N,&K,&P);
	int dp[N];
	int count = 0;
	memset(dp,-1,sizeof(dp));
	FOR(i,N)scanf("%d",&belt[i]);
	scanf("%s",dog);
	int len = strlen(dog);
	int ans;
	int itertimes = 0;
	FOR(i,len){
		if(dog[i] == '!'){
			count = (count+1)%N;
		}
		else{
			if(dp[count] == -1){
			    for(int j=0; j<N; j++) {
			        temp_belt[j] = belt[foo(j-count+N,N)]; // perform shifting shiftTimes times ot right
			    }
			    ans = getmaxones2(temp_belt,N,K);
			    dp[count] = ans;
			}
			else{
				ans = dp[count];
			}
			itertimes++;
		    printf("%d\n",ans);
		}
	}
	return 0;
}   
