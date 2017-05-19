//#include <bits/stdc++.h>
#include <bits/stdc++.h>


using namespace std;
const long long limit = 100005;
 
vector<bool> prime(limit,true);

vector<int> primes;
void seive(){
    for(long long i=2;i<limit;i++){
        if(prime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<limit;j+=i){
                prime[j]=false;
            }
        }
    }
    return;
}

int main(){
	seive();
	vector<int>::iterator it = primes.begin();
	int c = 0,i = 0;
	while(it != primes.end()){
		printf("%d ",primes[i]);
		c++;
		i++;
		it++;
	}
	//printf("\n\n\n start bellow =============\n\n\n");
	//for(int i = 0;i<primes.size();i++) printf("%d ",prime[i]);
	return 0;
}
