/*
  Problem 	: Oct17 long challenge (https://www.codechef.com/OCT17/problems/CHEFGP)
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
typedef list<char> STR;
typedef list<char>::iterator STRIT;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		int n, numa = 0, numb = 0, sx, sy, x, y;
		string str;
		cin>>str;
		cin>>x>>y;
		
		STR happys;
		STRIT bp, it;
		
		n = str.length();
		for(int i=0;i<n;i++){
			if(str[i]=='a') numa++;
			else numb++;
		}
		
		if(numb == numa){
			bool switchf = true;
			n = numa+numb;
			
			for(;;) {
				if(!switchf) happys.pb('b'), numb--, switchf = true;
				else happys.pb('a'), numa--, switchf = false;
				if(!numb && !numa) break;
			}
		}
		else if(numb > numa){
			int diff = 0, q = 1, balance;
			sx = x, sy = y, n = numb;
			if(y>n) y = n;
			for(int i=0; i<numb; i++) happys.pb('b');
			
			// place y diff a
			it = happys.begin();
			while(numa){
				if(n >= diff+y){
					it = next(it, y); // jump to next yth location
					happys.insert(it, 'a'), numa--, n++, diff += y+1;
				} else break;
			}
			
			it = happys.begin(); ++it;
			while(q <= n && numa){
				bp = prev(it);
				if((*it) == 'b' && (*bp) == 'b') happys.insert(it, 'a'), n++, numa--, q = q+2;
				else q++;
				++it;
			}
			
			q = 0;
			balance = 0;
			it = happys.begin();
			
			while(q<n){
				if((*it)=='b'){
					if(sy == balance) happys.insert(it, '*'), balance = 1, n++;
					else balance++;
				} else balance = 0;
				q++, ++it;
			}
		}
		else{
			int diff = 0, q = 1, balance;
			sx = x, sy = y, n = numa;
			if(x>n) x = n;
			for(int i=0; i<numa; i++) happys.pb('a');
			
			// place x diff b
			it = happys.begin();
			while(numb){
				if(n >= diff+x){
					it = next(it, x); // jump to next xth location
					happys.insert(it, 'b'), numb--, n++, diff += x+1;
				} else break;
			}
			
			it = happys.begin(); ++it;
			while(q <= n && numb){
				bp = prev(it);
				if((*it) == 'a' && (*bp) == 'a') happys.insert(it, 'b'), n++, numb--, q = q+2;
				else q++;
				++it;
			}
			
			q = 0;
			balance = 0;
			it = happys.begin();
			
			while(q<n){
				if((*it)=='a'){
					if(sx == balance) happys.insert(it, '*'), balance = 1, n++;
					else balance++;
				} else balance = 0;
				q++, ++it;
			}			
		}
		
		for(it = happys.begin(); it!= happys.end(); ++it) cout<<(*it);
		cout<<"\n";
	}
	
	return 0;
}
