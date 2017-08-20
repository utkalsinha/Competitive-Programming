/*
  Problem 	: Codechef August - 2017- https://www.codechef.com/AUG17/problems/CHEFMOVR
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
#include <stdio.h>

#define MAXV 100005
#define gc getchar_unlocked
typedef long long ll;

ll equalv,n,d;
long long rsum, ans, a[MAXV];
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }

ll getbal(ll i, ll extra){
    if(i>=n) return 0;
    if(a[i]>= equalv+extra){
        a[i] -= extra;
        return 1;
    }
    ll res = getbal(i+d, extra+equalv-a[i]);
    if(!res) return 0;
    ans += extra + equalv - a[i];
    a[i] = equalv;
    
    return 1;
}

int main(){
    int T = rin();
    
    while(T--){
        ll i, ret, extra;
        ans = rsum = 0;
        
        n = rinl(), d = rinl();
        for(i =0;i<n;i++) a[i] =rinl(), rsum += a[i];
        
        if(rsum % n != 0) ans = -1;
        else{
            equalv = rsum/n;
            for(i=0;i<n;i++){
                if(a[i] != equalv){
                    if(a[i] > equalv){
                        extra = a[i] - equalv;
                        if(i+d>=n){
                            ans = -1;
                            break;
                        }
                        a[i+d] += extra, a[i] = equalv;
                        ret = 1;
                    } else if(a[i] < equalv){
                        extra = equalv - a[i];
                        ret = getbal(i+d, extra);
                    }
                    if(!ret){
                        ans = -1;
                        break;
                    }
                    ans += extra;
                }
            }    
        }
        
        printf("%lld\n", ans);
    }
    
	return 0;
}
