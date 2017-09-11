/*
  Problem 	: Codechef -September Challenge (https://www.codechef.com/SEPT17/problems/CHEFPDIG)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
 
typedef unordered_map<int, int> HASH;
typedef unordered_map<int, int>::iterator HASHIT;
 
void printcombinations(){
	int  t, x, y, u, v, hashsize, strlen;
	set<char> finalchars;
	HASH h;
	string str;
	HASHIT iter1, iter2, itert;
	cin>>str;
	strlen = str.length();
	
	for(int i=0;i<strlen;i++) h[str[i]-'0']++;
	
	for(auto itr = h.begin(); itr != h.end(); ++itr){
		if(itr->second > 1){
			t = itr->first*10 + itr->first;
			if(t>='A' && t <= 'Z') finalchars.insert((char)(t));
		}
	}
	
	hashsize = h.size();
	for(x =0, iter1 = h.begin(); x < hashsize-1; x++, ++iter1){
		itert = iter1, iter2 = ++itert;
		u = iter1->first;
		for(y = x+1; y< hashsize && iter2 != h.end(); y++, ++iter2){
			
			v = iter2->first;
			
			t = u*10 + v;
			if(t>='A' && t <='Z') finalchars.insert((char)(t));
			
			t = v*10 + u;
			if(t>='A' && t <='Z') finalchars.insert((char)(t));
		}
	}
	
	for(auto itera = finalchars.begin(); itera != finalchars.end(); ++itera) cout<<*itera;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin>>T;
	
	while(T--){
		printcombinations();
		cout<<"\n";
	}
	
	return 0;
} 
