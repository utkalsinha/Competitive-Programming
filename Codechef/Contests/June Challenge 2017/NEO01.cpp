/*
  Problem :	Codechef - NEO01 - https://www.codechef.com/JUNE17/problems/NEO01
  Author : Utkal Sinha
  Contact : info@utkalsinha.com
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
void solve(){
	ll n, i, multiplier = 0, pos_count = 0;
	long long int ans = 0, tempSum = 0, possum = 0, del;
	scanf("%lld",&n);
	ll data[n];
	for(i = 0;i<n;i++) scanf("%lld",&data[i]);
	vector<ll> v(data, data+n);
	sort(v.begin(), v.end());
	ll boundary = 0; // dividing negatives and positives
	
	ll l = 0;
	ll r = n-1;
	
	while(l<=r){
		int m = l + (r-l)/2;
		if(v[m] < 0){
			if(((m+1)<n && v[m+1] >=0) || (m== (n-1))) {
				boundary = m+1;
				break;
			}
			else{
				l = m+1;
			}
		}
		else if(v[m] == 0){
			if(((m-1)>=0 && v[m-1] < 0) || m==0){
				boundary = m;
				break;
			}
			else {
				r = m-1;
			}
		}
		else {
			r = m-1;
		}
	}
	
	//for(i = 0;i<n;i++) printf("%d ", v[i]); printf("\n\n");
	//printf("Boundary point = %d\n", boundary);
	// handle positives
	pos_count = n-boundary;
	possum= 0;
	for(ll p = boundary;p<n;p++){
		possum = possum + v[p];
	}
	
	long long int curmax = pos_count * possum;
	long long int temp;
	ll nt;
	for(i = boundary-1;i>=0;i--){
		temp = possum + v[i];
		nt = pos_count + 1;
		if(curmax <= nt * temp ){
			curmax = nt * temp;
			possum = temp;
			pos_count = nt;
		} else break;
	}
	
	for(;i>=0;i--) curmax += v[i];
	printf("%lld\n",curmax);
}
 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}  
