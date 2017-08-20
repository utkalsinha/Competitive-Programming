#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mt make_tuple
#define gc getchar
#define MAXV 100005
 
typedef long long ll;
 
typedef struct {
	bool present;
	ll hddbase;
	ll hddlimit;
	ll cid;
} CLIENT;
 
CLIENT clients[MAXV];
vector<tuple<ll, ll, ll, ll, ll>> hdds;
 
int main() {
	// variables
    ll n, h, p , r, w, c, lhddi, TS = 0, in = 0;
    ll cmdtype, cid, hid, qc, pc, penalty;
    
    memset(clients, 0, sizeof(clients));
    
    cin>>n>>h;
    
    while(h--){
    	cin>>p>>r>>w>>c;
    	hdds.pb(mt(c, p, r, w, in));
    	in++;
	}
	
	cin>>penalty;
		
	sort(hdds.begin(), hdds.end());
	
    lhddi = get<4>(hdds[hdds.size() - 1]);
    TS = get<0>(hdds[hdds.size() - 1]);
    
    // accept queries
    cout<<"p b "<<lhddi<<endl;
    
    while(n--){
    	// get next query
		cout << "g" << endl;
    	cin>>cmdtype;
    	
    	if(cmdtype == 0){
    		cin>>cid>>qc;
    		cout<<"p s -1 -1"<<endl;
		}
		else if(cmdtype == 1){
			cin>>cid>>pc;
			cout<<"p i -1 -1"<<endl;
		}
		else if(cmdtype == 2){
			cin>>hid;
			memset(clients, 0, sizeof(clients));
		}
	}
    
    // end the process
    cout<<"end"<<endl;
    
    return 0;
} 
