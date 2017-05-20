#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef long long int ll;

ll getmin(ll a, ll b){
	return (a>b?b:a);
}

ll findsol(ll R[], ll n, ll s, ll t){
	ll z = s, ans = -1,i,j, curmin = LLONG_MAX;
	int flag;
	while(z!= t){
		flag = 0;
		printf("\n\n\n\n>>z = %lld, t = %lld\n",z,t);
		ll jumps[n];
		for(i = 0;i<n;i++) jumps[i] = LLONG_MAX;
		jumps[z] = 0;
		i = (((z+1)==n )? 0: z+1);
		while(1){
			j = z;
			printf("j = %lld, i = %lld\n",j,i);
			while(j!=i){
				if(((R[j]+j )%n)>= i){
					if(jumps[i] > jumps[j]+1){
						jumps[i] = jumps[j] + 1;
						printf("=======================> Enttered, jumps[%lld] = jumps[%lld]+1 | Jump[%lld] = %lld\n",i,j,j,jumps[j]);
					}
				}
				printf("===============> j = %lld, i = %lld | (R[%lld]+%lld)\%% %lld >= %lld \n",j,i,j,j,n,i);
				j = (((j+1)==n)?0:j+1);
			}
			i = (((i+1)==n)?0:i+1);
			if(flag) break;
			if(i==t) flag = 1;
		}
		
		i = ((i==0)? n-1: i-1);
		printf("jump[0] = %lld, source = %lld, i = %lld, jumps[%lld] = %lld, curmin = %lld, min = %lld\n",jumps[0],z,i,i,jumps[i],curmin, getmin(curmin, jumps[i]));
		getchar();
		curmin = getmin(curmin, jumps[i]);
		
		if(!z) z= n-1;
		else z--;
	}
	if(curmin == LLONG_MAX) return -1;
	else return curmin;	
}

int main(){
	ll n,s,t,i,ans;
	scanf("%lld %lld %lld",&n,&s,&t);
	ll R[n],g,seed,p;
	scanf("%lld %lld %lld %lld", &R[0], &g,&seed,&p);
	// initialize R
	for(i = 1;i<n;i++) R[i] = (R[i-1]*g+seed)%p;
	// findsolution
	ans = findsol(R, n, s, t);
	printf("%lld\n", ans);
	
	return 0;
}
