/*
  Problem 	: Codechef - July Challenge - 2017 - EXPTREE - https://www.codechef.com/JULY17/problems/EXPTREE
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif

#define mod7 1000000007
#define mod9 1000000009

typedef long long ll;
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }

#define bsf __builtin_ctzll

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	if (b == 0) return a;
	int shift = bsf(a|b);
	a >>= bsf(a);
	do {
    	b >>= bsf(b);
    	if (a > b) swap(a, b);
		b -= a;
	} while (b);
	return a << shift;
}


ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

int main(){
	int T;
	ll n;
	ll nt,p,q,k,ans1,ans2;
	T = rin();
	while(T--){
		n = rinl();
		nt = n%mod7;
		p = (nt*(nt-1)) % mod7;
		q = ((nt<<2)-6) % mod7;
		k = gcd(p,q);
		p = p/k;
		q = q/k;
		q = modInverse(q,mod7);
		ans1 = (p*q)%mod7;
		
		nt = n%mod9;
		p = (nt*(nt-1)) % mod9;
		q = ((nt<<2)-6) % mod9;
		k = gcd(p,q);
		p = p/k;
		q = q/k;
		q = modInverse(q,mod9);
		ans2 = (p*q)%mod9;
		
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}

