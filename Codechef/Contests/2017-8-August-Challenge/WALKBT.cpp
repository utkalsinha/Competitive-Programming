/*
  Problem 	: Codechef - August challenge - https://www.codechef.com/AUG17/problems/WALKBT
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/unordered_set.hpp>
#include <boost/algorithm/minmax.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using boost::unordered_set;
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	unsigned n, q, c;
	bool it1f, it2f;
	mp::cpp_int mod, x, ans;
	mp::cpp_int r(1);
	char type;
 
	cin>>T;
	
	while(T--){
		cin>>n>>q;
		mod = r<<n;
		
		set<mp::cpp_int> s;
		set<mp::cpp_int>::iterator it1, it2;
		pair<mp::cpp_int, mp::cpp_int> tp;
		
		// solve
		x = 0;
		ans = 1;
		while(q--){
			cin>>type;
			if(type=='!'){
				cin>>c;
				x = (x+(r << c))%mod;
				
				it1f = it2f = false;
				
				auto ret = s.emplace(x);
				
				if(ret.second){
					auto it = ret.first;
					if(it != s.begin()){
						it1 = prev(it);
						it1f = true;
					}
					it2 = next(it);
					if(it2 != s.end()){
						it2f = true;
					}
					if(it1f && it2f){
						tp = minmax(x^(*it1), x^(*it2));
						ans += 1 + msb(tp.first);
					}
					else if(it1f && !it2f){
						ans += 1 + msb(x^(*it1));
					}
					else if(!it1f && it2f){
						ans += 1 + msb(x^(*it2));
					}
					else {
						ans += n;
					}
				}
			}
			else{
				cout<<ans<<'\n';
			}
		}
	}
 
	return 0; 
} 
