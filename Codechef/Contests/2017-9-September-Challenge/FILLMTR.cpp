/*
  Problem 	: Codechef - September Challenge (https://www.codechef.com/SEPT17/problems/FILLMTR)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define pb push_back
#define mp make_pair
 
typedef vector<pair<int, int>> EDGE;
inline int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
bool smooth(bool already_counted[], EDGE edges[], int i, int j, int n, int A[]){
	int r, s, t;
   	queue<int> smoothq;
    bool smoothd[n] = {0};
    int y = edges[i][j].first;
    int v = edges[i][j].second;
   	if(!v) {
   		A[y] = A[i];
	}
   	else {
   		A[y] = (A[i]==2?1:2);
	}
   	smoothq.push(y);
	smoothd[y] = true;
   	while(!smoothq.empty()){
   		t = smoothq.front(), smoothq.pop();
   		for(int z=0;z<edges[t].size();z++){
   			r = edges[t][z].first;
   			s = edges[t][z].second;
   			if(A[r]){
   				if(abs(A[t]-A[r]) != s){
   					if(smoothd[t] && smoothd[r]){
   						return false;
   					}
   					else if(smoothd[t]){
   						if(s) {
   							A[r] = (A[t]==2?1:2);
						}
   						else {
   							A[r] = A[t];
						}
   						smoothq.push(r), smoothd[r] = true;
   					}
   					else if(smoothd[r]){
   						if(s) {
   							A[t] = (A[r]==2?1:2);
						}
   						else {
   							A[t] = A[r];
						}
   						smoothq.push(t), smoothd[t] = true;
   					}
   				}
   			}
   			else {
   				if(s) {
   					A[r] = (A[t]==2?1:2);
				}
   				else {
					A[r] = A[t];   
				}
   			}
   		}
   		if(!already_counted[t]) {
   			already_counted[t] = true;
		}
   	}
 
   	return true;
}
    
bool go(int n, EDGE edges[]){
   	bool already_counted[n] = {false};
   	int A[n] = {0};
   	int  w, v;
   	for(int i=1;i<n;i++){
   		if(!already_counted[i] && edges[i].size()>0){
   			for(int j=0;j<edges[i].size();j++){
   				w = edges[i][j].first;
   				v = edges[i][j].second;
   				if(A[i] && A[w]){
   					if(abs(A[i]-A[w]) != v){
   						if(!smooth(already_counted, edges, i, j, n, A)) {
   							return false;
						}
   					}
   				}
   				else if(A[i]){
   					if(v) {
   						A[w] = (A[i]==2?1:2);
					}
   					else {
   						A[w] = A[i];	
					}
   				}
   				else if(A[w]){
   					if(v){
   						A[i] = (A[w]==2?1:2);	
					}
   					else{
   						A[i] = A[w];
					}
   				}
   				else{
   					if(v) {
   						A[i] = 1, A[w] = 2;
					}
   					else {
   						A[i] = A[w] = 1;
					}
   				}
   			}
 
   			already_counted[i] = false;
   		}
   	}
   	return true;
}
 
int main(){
	int T = rin();
	while(T--) {
	   	int n, q, i, j, v;
	   	bool foundarray = true;
	   	n = rin(), q = rin();
	   	EDGE edges[n+1];
		while(q--){
	   		i = rin(), j = rin(), v = rin();
	   		if(foundarray){
	   			if(i==j) {
	   			    if(v) {
	   			    	foundarray = false;
					}
	   			}
	   			else {
	   				edges[i].pb(mp(j,v));
					edges[j].pb(mp(i,v));	
				}
			}
		}
		if(foundarray) {
			foundarray = go(n+1, edges);
		}
		if(foundarray) printf("yes\n");
		else printf("no\n");
	}
	return 0;
} 
