/*
  Problem 	: Oct long Challenge 2017 (https://www.codechef.com/OCT17/problems/SHTARR)
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include <bits/stdc++.h>
using namespace std;
#define USEWINDOWS 0 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif
#define pb push_back
#define mp make_pair
#define MIN_BLOCK_SIZE 100
int blocksize, num_of_blocks;
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
typedef struct {
	int maxheight;		// maximum height in current block
	int beginheight; 	// beginning height of current block
	int num_bars;		// number of bars subsequently greater than current block begin bar
} BLOCKNODE;
 
void preprocess(int a[], BLOCKNODE blks[], int n){
	for(int i=0, ai;i<num_of_blocks;i++){
		ai = blocksize*i;
		int maxtmp = -1, num_bars = 0, begi = ai;
		for(int j = 0; j<blocksize && ai<n; j++, ai++) if(maxtmp < a[ai]) maxtmp = a[ai], num_bars++;
		blks[i].maxheight = maxtmp, blks[i].beginheight = a[begi], blks[i].num_bars = num_bars;
	}
}
 
int getcount(int a[], BLOCKNODE blks[], int blkstarti, int n, int llim, int hlim, int curblocklim){
	int maxtmp = llim, num_bars = 0;
	for(int i=blkstarti;i<curblocklim && i<n; i++){
		if(maxtmp < a[i]) {
			maxtmp = a[i], num_bars++;
			if(hlim < a[i]) return num_bars;
		}
	}
	return num_bars;
}
 
int printans(int a[], BLOCKNODE blks[], int n){
	int i = rin()-1, l = rin(), r = rin(), bar = 0, blkindex = i/blocksize, hlim = r-1, llim = l-1;
	int curblocklim = blocksize*(blkindex+1);
	
	for(;i<curblocklim && i<n; i++){
		if(llim < a[i]){
			bar++, llim = a[i];
			if(hlim < a[i]) return bar;
		}
	}
 
	// process subsequent blocks
	int blkstarti;
	for(int j = blkindex+1; j<num_of_blocks; j++){
		blkstarti = blocksize*j, curblocklim = blocksize*(j+1);
		if(llim < blks[j].beginheight){
			if(hlim >= blks[j].maxheight) {
				bar += blks[j].num_bars;
				llim = blks[j].maxheight;
			}
			else{
				bar += getcount(a, blks, blkstarti, n, llim, hlim, curblocklim);
				return bar;
			}
		}
		else{
			if(hlim < blks[j].maxheight){
				bar += getcount(a, blks, blkstarti, n, llim, hlim, curblocklim);
				return bar;
			}
			else{
				if(llim < blks[j].maxheight){
					bar += getcount(a, blks, blkstarti, n, llim, hlim, curblocklim);
					llim = blks[j].maxheight;
				}
			}
		}
	}
	return bar;
}
 
void updateblock(int a[], BLOCKNODE blks[], int n, int xi){
	int blkindex, blkstarti, curblocklim, maxtmp, num_bars, begi;
	blkindex = xi/blocksize, blkstarti = blocksize*blkindex, curblocklim = blocksize*(blkindex+1), maxtmp = -1, num_bars = 0, begi = blkstarti;
	
	for(; blkstarti<curblocklim && blkstarti<n; blkstarti++) if(maxtmp < a[blkstarti]) maxtmp = a[blkstarti], num_bars++;
	
	blks[blkindex].maxheight = maxtmp, blks[blkindex].beginheight = a[begi], blks[blkindex].num_bars = num_bars;
}
 
void solve(){
	int n = rin(), q = rin(), a[n], x, xi;
	for(int i=0;i<n;i++) a[i] = rin();
	
	// solve
	blocksize = MIN_BLOCK_SIZE;
	num_of_blocks = (n%blocksize==0? n/blocksize: (n/blocksize +1));
	BLOCKNODE blks[num_of_blocks];
	
	memset(blks, 0, sizeof(blks));
	// preprocess in O(n)
	preprocess(a, blks, n);
	
	// 	process queries in O(sqrt(n))
	char qt;
	while(q--){
		qt = gc();
		if(qt == '?') printf("%d\n", printans(a, blks, n));
		else {
			// update in O(blocksize)
			xi = rin()-1, x = rin();
			a[xi] += x;
			if(xi>=1 && xi<n-1 && a[xi]<a[xi-1] && a[xi]<a[xi+1]);
			else updateblock(a, blks, n, xi);
		}
	}
}
 
int main(){
	int T = rin();
	while(T--) solve();
	return 0;
} 
