/*
  Problem 	:	Codeforces Round #422 (Div. 2) - http://codeforces.com/contest/822/problem/B
  Author 	: 	Utkal Sinha
  Contact 	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,i,j,k,minc,temp;
	scanf("%d %d",&n,&m);
	char s[n+1];
	char t[m+1];
	scanf("%s",s);
	scanf("%s",t);
	vector<int> mini;
	minc = INT_MAX;
	for(i = 0;i<m-n+1;i++){
		temp = 0;
		vector<int> index;
		for(j = 0,k = i;j<n;j++,k++){
			if(s[j] != t[k]){
				temp++;
				index.push_back(j+1);
			}
		}
		if(minc>temp){
			minc = temp;
			mini = index;
		}
	}
	printf("%d\n",minc);
	for(vector<int>::iterator it = mini.begin(); it != mini.end(); ++it)printf("%d ",*it);
	
	return 0;
}
