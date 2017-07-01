/*
  Problem : HackerRank - Week of Code 33 - Palindromic table - https://www.hackerrank.com/contests/w33/challenges/palindromic-table
  Author : Utkal Sinha
  Contact : info@utkalsinha.com
*/
#include <stdio.h>
#include <string.h>

bool is_num_of_odd_frequency_greater_than_one(int freq[]){
	int count = 0;
	for(int i = 0;i<10;i++) {
		if(freq[i] %2 != 0) count++;
		if(count > 1) return true;	
	}
	return false;
}

int main(){
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	int table[n][m];
	for(i = 0;i<n;i++)for(j = 0;j<m;j++) scanf("%d",&table[i][j]);	
		
	// end solving
	
	// printf ans
	
	return 0;
}

