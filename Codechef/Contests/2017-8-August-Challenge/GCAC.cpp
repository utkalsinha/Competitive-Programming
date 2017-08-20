/*
  Problem 	: Codechef August - 2017- https://www.codechef.com/AUG17/problems/GCAC
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
#define pb push_back
#define mp make_pair
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int main() {
    int T = rin(), t, a, b;
    
    while(T--){
        int n = rin(), m = rin(), cursal, cursali,selcannum = 0, compselcount=0;
        char c;
        vector<int> cmr;
        vector<pair<int, int>> comps;
        bool compselected[1000] = {false};
        
        long long int totalsal = 0;
        
        for(int i=0;i<n;i++) t = rin(), cmr.push_back(t);
        for(int i=0;i<m;i++) a = rin(), b = rin(), comps.pb(mp(a,b));
        
        for(int i=0;i<n;i++){
            cursal = 0;cursali = -1;
            for(int j=0;j<m;j++){
                c = getchar();
                if(c=='1'){
                    if(comps[j].second && comps[j].first >= cmr[i] && comps[j].first > cursal){
                        cursal = comps[j].first;
                        cursali = j;
                    }
                }
            }
            c = getchar();
            if(cursali != -1){
                selcannum++;
                comps[cursali].second--;
                if(!compselected[cursali]) compselected[cursali] = true, compselcount++;
                totalsal += cursal;
            }
            
        }
        printf("%d %lld %d\n", selcannum, totalsal, m-compselcount);
    }
    
    return 0;
}
