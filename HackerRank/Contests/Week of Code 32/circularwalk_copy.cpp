#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef long long int ll;

ll getmin(ll a, ll b){
	return (a>b?b:a);
}

ll findsol(ll R[], ll n, ll s, ll t){
	ll temp;
	ll minr, minl;
	if(s==t) return 0;
	if(R[s] == 0) return LLONG_MAX;
	// rightchild
	if(t>s){
		if(s+R[s] >= t) return 1;
		else {
			minr = findsol(R,n,(s+R[s])%n,t);
			if(minr != LLONG_MAX) minr++;
		}
	} else {
		if(s+R[s] >= s+t) return 1;
		else {
			minr = findsol(R,n,(s+R[s])%n,t);
			if(minr != LLONG_MAX) minr++;
		}
	}
	// leftchild
	if(t<s){
		if(s-R[s] <= t) return 1;
		else {
			temp = s-R[s];
			if(temp<0) temp += n;
			minl = findsol(R,n,temp,t);
			if(minl != LLONG_MAX) minl++;
		}
	} else {
		if(s-R[s] +n<= t) return 1;
		else {
			minl = findsol(R,n,s-R[s]+n,t);
			if(minl != LLONG_MAX) minl++;
		}
	}
	return getmin(minl,minr);
}

int main(){
	ll n,s,t,i,ans;
	scanf("%lld %lld %lld",&n,&s,&t);
	ll R[n],g,seed,p;
	scanf("%lld %lld %lld %lld", &R[0], &g,&seed,&p);
	// initialize R
	for(i = 1;i<n;i++) R[i] = (R[i-1]*g+seed)%p;
	// findsolution
	ans = findsol(R, n, s, t);
	if(ans == LLONG_MAX) ans = -1;
	printf("%lld\n", ans);
	
	return 0;
}
