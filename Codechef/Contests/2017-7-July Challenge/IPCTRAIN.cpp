/*
  Problem 	: Codechef - July Chaldepthge 2017 - IPCTRAIN - https://www.codechef.com/JULY17/problems/IPCTRAIN
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define MAXV 100005
typedef long long ll;
int n,depth,TotalDays,hp[MAXV];
ll ans;
typedef struct TRAINER {
    int di,ti,si;
    bool operator < (const TRAINER &oth_trs) const { return di < oth_trs.di; }
} TRAINER;
TRAINER trs[MAXV];

inline int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
void gethp(){ hp[1]=hp[depth]; hp[depth] = 0; depth--; for (int i=1; (i<<1) <= n;){ int j; if (trs[hp[i<<1]].si>trs[hp[i<<1|1]].si || (i<<1|1)>n) j = i<<1; else j = i<<1|1; if (trs[hp[j]].si > trs[hp[i]].si) swap(hp[j],hp[i]), i = j; else return; }}
void inserthp(int p){ hp[++depth] = p; for(int j = depth; j>1; j>>=1) if (trs[hp[j]].si>trs[hp[j>>1]].si&&trs[hp[j]].si>trs[hp[j>>1]].si) swap(hp[j],hp[j>>1]); else break; }
inline void resetMems(){ memset(trs,0,sizeof(trs)); memset(hp,0,sizeof(hp));}

int main(){
	int T;
	T = rin();
    while(T--){
        n = rin();
		TotalDays = rin();
		depth = ans = 0;
		resetMems();
        int j=1;
        for (int i=1; i<=n; i++) trs[i].di = rin(), trs[i].ti = rin(), trs[i].si = rin();
       	sort(trs+1,trs+n+1);
        for (int days=1; days<=TotalDays; days++){
        	while ((j<=n) && (trs[j].di == days)) inserthp(j), j++;
            if (!depth) continue;
        	int p = hp[1]; 
			trs[p].ti--;
            if (!trs[p].ti) gethp();
        }
        for (int i=1; i<=n; i++) ans += (ll)trs[i].si * trs[i].ti;
        
        printf("%lld\n",ans);
    }
    return 0;
 }
