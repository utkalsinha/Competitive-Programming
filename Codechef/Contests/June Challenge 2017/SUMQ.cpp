/*
  Problem	:	Codechef - SUMQ - https://www.codechef.com/JUNE17/problems/SUMQ
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/
 
#include <bits/stdc++.h>
using namespace std;
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
 
#define mod 1000000007
 
typedef long long ll;
 
ll rd_int() {
	int flag=0;
	char c = gc();
	if(c=='-')flag=1;
	while(c<'0' || c>'9') c = gc();
	ll res = 0;
	while(c>='0' && c<='9'){
		res = 10 * res + c - 48;
		c = gc();
	}
	if(!flag)return res;
	else return (-res);
}
 
void solve(){
	ll p,q,r,i,j,k,t,ans = 0,a, ab_a_less_count, bc_c_less_count, ac_c_sum_less_than_b;
	p = rd_int(), q = rd_int(),	r = rd_int();
	ll A[p],B[q],C[r];
	for(i = 0;i<p;i++) A[i] = rd_int();
	for(i = 0;i<q;i++) B[i] = rd_int();
	for(i = 0;i<r;i++) C[i] = rd_int();
	sort(A,A+p);
	sort(B,B+q);
	sort(C,C+r);
	
	// store running sums (O(n))
	ll A_sum[p], C_sum[r], sumv = 0;
	A_sum[0] = A[0];
	for(i = 1;i<p;i++) A_sum[i] = (A_sum[i-1] + A[i]) % mod;
	
	C_sum[0] = C[0];
	for(k = 1;k<r;k++) C_sum[k] = (C_sum[k-1] + C[k]) % mod;
	
	// count less than for array A (O(n))
	ll A_less_B_count[q];
	a = 0;
	for(j=0;j<q;j++){
		for(i=a;i<p && B[j]>=A[i];i++);
		A_less_B_count[j] = i;
		a = i;
	}
	// count less than for array C (O(n))
	ll C_less_B_count[q];
	a = 0;
	for(j=0;j<q;j++){
		for(k=a;k<r && B[j]>=C[k];k++);
		C_less_B_count[j] = k;
		a = k;
	}
	// calculate actual solution (O(n))
	ans = 0;
	for(j=0;j<q;j++){
		// B2 square section
		if(A_less_B_count[j] != 0 &&  C_less_B_count[j] != 0){
			a = (B[j] * B[j]) % mod;
			a = (a * A_less_B_count[j]) % mod;
			a = (a * C_less_B_count[j]) % mod;
			ans = (ans + a) % mod;
			// AB section
			ab_a_less_count = A_sum[A_less_B_count[j]-1];
			a = (B[j] * ab_a_less_count) % mod;
			bc_c_less_count = C_less_B_count[j];
			a = (a * bc_c_less_count) % mod;
			ans = (ans + a) % mod;
			// BC section
			bc_c_less_count = C_sum[C_less_B_count[j]-1];
			a = (B[j] * bc_c_less_count) % mod;
			ab_a_less_count = A_less_B_count[j];
			a = (a * ab_a_less_count) % mod;
			ans = (ans + a) % mod;
			// AC section
			a = (A_sum[A_less_B_count[j]-1] * C_sum[C_less_B_count[j]-1]) % mod;
			ans = (ans + a) % mod;
		}
	}
	
	printf("%lld\n",ans);
}
 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
