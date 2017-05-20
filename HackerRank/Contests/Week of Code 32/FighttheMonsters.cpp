/*
  Problem	:	HackerRank Contest - Week of Code 32 (Fight the Monsters! - https://www.hackerrank.com/contests/w32/challenges/fight-the-monsters)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(ll arr[], ll l, ll m, ll r){
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
    ll L[n1], R[n2];
    for (i = 0; i < n1; i++)L[i] = arr[l + i];
    for (j = 0; j < n2; j++)R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(ll arr[], ll l, ll r){
    if (l < r){
        ll m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
	ll n,hit,t, ans = 0,i, timeTokill = 0;
	scanf("%lld %lld %lld",&n,&hit,&t);
	ll h[n];
	for(i = 0;i<n;i++) scanf("%lld",&h[i]);
	mergeSort(h,0,n-1);
	i = 0;
	bool flag = true;
	for(int i = 0;i<n;i++){
		timeTokill = h[i]/hit + (!(h[i]%hit)?0:1);
		if(timeTokill > t){
			break;
		}
		ans++;
		t -= timeTokill;
	}
	printf("%lld\n",ans);
	return 0;
}
