#include <stdio.h>
#include <string.h>
#include <limits.h>
#define gc getchar
 
typedef long long ll;
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
long long int rinl() { char c = gc(); while(c<'0' || c>'9') c = gc(); long long int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
void posneg(ll &x) { register int c = gc(); x = 0; int neg = 0; for(;((c<48 || c>57) && c != '-');c = gc()); if(c=='-') {neg=1;c=gc();} for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} if(neg) x=-x;}
 
#define MAXV 100005
#define BLOCKSIZE 98 // this should be less than or equal to 100 as I didn't check for 100 limit
#define MAXNUMOFBLOCK 100005
#define NEGINFINITY 1
 
typedef struct{
    ll delta;
    ll maxv;
    ll startv;
    ll maxindex;
    ll startindex;
    ll numberofstepsInBlock;
} BLKNODE;
 
ll a[MAXV];
BLKNODE blk[MAXNUMOFBLOCK];
ll n,q, numofblocks;
 
void decompose(){          // Done
    numofblocks = n/BLOCKSIZE + ((n%BLOCKSIZE==0)?0:1);
    ll j, k, numberofsteps, tempmax, tempmaxi;
 
    j = 1;
    for(ll i=0;i<numofblocks;i++){
        numberofsteps = 0;
        blk[i].startv = a[j];
        blk[i].startindex = j; 
        tempmax = a[j];
        tempmaxi = j;
        k = 1;
        // process block
        while(j<=n && k<=BLOCKSIZE){
            if(tempmax < a[j]) tempmax = a[j], tempmaxi = j, numberofsteps++;
            j++, k++;
        }
 
        blk[i].maxv = tempmax;
        blk[i].maxindex = tempmaxi;
        blk[i].numberofstepsInBlock = numberofsteps;
        blk[i].delta = 0; // delta = 0 means that the block has not been modified
    }
}
 
void push(ll blkindex){
    ll li, rightlimit, tempmax, tempmaxi, numofsteps;
    li = 1 + BLOCKSIZE*blkindex;
    rightlimit = BLOCKSIZE*(blkindex + 1);
    
    tempmax = a[li] + blk[blkindex].delta;
    tempmaxi = li;
    numofsteps = 0;
    
    while(li<=rightlimit && li <= n){
        a[li] = a[li] + blk[blkindex].delta;
        if(tempmax < a[li]) tempmax = a[li], tempmaxi = li, numofsteps++;
        li++;
    }
    blk[blkindex].startv = a[1 + BLOCKSIZE*blkindex], blk[blkindex].maxv = tempmax, blk[blkindex].maxindex = tempmaxi, blk[blkindex].numberofstepsInBlock = numofsteps, blk[blkindex].delta = 0;
}
 
ll getindex(){             
    ll l, k, ans, rightlimit, curval, blkindex;
    posneg(l), posneg(k);
 
    blkindex = (l-1)/BLOCKSIZE;
    rightlimit = BLOCKSIZE*(blkindex + 1);
    
    push(blkindex);
    
    curval = a[l];
    ans = l;
    
    // first start block
    l++;
    while(k>0 && l<= rightlimit && l<=n){
        if(curval < a[l]) {
            if((l-ans) <= 100) ans = l, curval = a[l], k--;
            else return ans;
        }
        l++;
    }
        
    // point to the next block
    blkindex++;
    l = 1 + BLOCKSIZE*blkindex;
    // done till here
    
    while(k>0 && l <= n){
 
        if(curval < (blk[blkindex].startv + blk[blkindex].delta)) {
            if(k >= (blk[blkindex].numberofstepsInBlock+1)) {
                if(((blk[blkindex].maxindex - ans) <= 100) || ((blk[blkindex].startindex - ans) <= 100)) {
                    ans = blk[blkindex].maxindex;
                    curval = blk[blkindex].maxv + blk[blkindex].delta;
                    k = k - blk[blkindex].numberofstepsInBlock - 1;
                } else return ans;
            } else {                        // k < (blk[blkindex].numberofstepsInBlock+1) (Your final block)
                push(blkindex);
                while(k>0 && l <= n){
                    if(curval < a[l]){
                        if((l-ans) <= 100) ans = l, curval = a[l], k--;
                        else return ans;
                    }
                    l++;
                }
            }
            // done till here
        } else if(curval > (blk[blkindex].startv + blk[blkindex].delta)){
            if(curval < (blk[blkindex].maxv + blk[blkindex].delta)){
                push(blkindex);
                while(k>0 && l <= blk[blkindex].maxindex && l<=n){
                    if(curval < a[l]){
                        if((l-ans) <= 100) ans = l, curval = a[l], k--;
                        else return ans;
                    }
                    l++;
                }
            }
        } else if(curval == (blk[blkindex].startv + blk[blkindex].delta)){
            if(k >= blk[blkindex].numberofstepsInBlock) {
                if(blk[blkindex].numberofstepsInBlock > 0){
                    if(((blk[blkindex].maxindex - ans) <= 100) || ((blk[blkindex].startindex - ans) <= 100)){
                        ans = blk[blkindex].maxindex;
                        k = k - blk[blkindex].numberofstepsInBlock;
                        curval = blk[blkindex].maxv + blk[blkindex].delta;
                    } else return ans; // this could be one of potential code breaking place
                }
            } else {
                // k < blk[blkindex].numberofstepsInBlock (should be the final block)
                if(curval < (blk[blkindex].maxv + blk[blkindex].delta)){
                    push(blkindex);
                    while(k>0 && l <=n){
                        if(curval < a[l]){
                            if((l-ans) <= 100) ans = l, curval = a[l], k--;
                            else return ans;
                        }
                        l++;
                    }
                }
            }
        }
        blkindex++;
        l = 1 + BLOCKSIZE*blkindex;
        if(l-ans > 100) return ans;
    }
    
    return ans;
}
 
void update(){
    ll l, r, x, blkindex, numofsteps, tempmax, tempmaxi, rightlimit, li;
    posneg(l), posneg(r), posneg(x);
 
    blkindex = (l-1)/BLOCKSIZE;
    rightlimit = BLOCKSIZE*(blkindex + 1);
    numofsteps = 0;
    li = 1 + BLOCKSIZE*blkindex;
    
    // process current block
    push(blkindex);
    
    //blk[blkindex].startv = a[li] + blk[blkindex].delta; << update this at the end
    tempmax = a[li];
    if(li == l) tempmax = tempmax + x;
    
    tempmaxi = li;
    while(li<l){
        if(tempmax < a[li]) tempmax = a[li], tempmaxi = li, numofsteps++;
        li++;
    }
    while(li <= r && li<=rightlimit && li <=n){
        a[li] = a[li] + x;
        if(tempmax < a[li]) tempmax = a[li], tempmaxi = li, numofsteps++;
        li++;
    }
    while(li <= rightlimit && li <= n){
        if(tempmax < a[li]) tempmax = a[li], tempmaxi = li, numofsteps++;
        li++;
    }
    blk[blkindex].startv = a[1 + BLOCKSIZE*blkindex], blk[blkindex].maxv = tempmax, blk[blkindex].maxindex = tempmaxi, blk[blkindex].numberofstepsInBlock = numofsteps, blk[blkindex].delta = 0;
    
    blkindex++;
    l = 1 + BLOCKSIZE*blkindex;
 
    while(l <= r){
        numofsteps = 0;
        rightlimit = BLOCKSIZE*(blkindex + 1);
        
        if((r-l+1) >= BLOCKSIZE) blk[blkindex].delta += x;
        else {
            // fianl block
            push(blkindex);
            
            tempmax = a[l] + x;
            tempmaxi = l;
            while(l<=r && l <= n){
                a[l] = a[l] + x;
                if(tempmax < a[l]) tempmax = a[l], tempmaxi = l, numofsteps++;
                l++;
            }
 
            while(l<= rightlimit && l <= n){
                if(tempmax < a[l]) tempmax = a[l], tempmaxi = l, numofsteps++;
                l++;
            }
            blk[blkindex].startv = a[1 + BLOCKSIZE*blkindex], blk[blkindex].maxv = tempmax, blk[blkindex].maxindex = tempmaxi, blk[blkindex].numberofstepsInBlock = numofsteps, blk[blkindex].delta = 0;
        }
        blkindex++;
        l = 1 + BLOCKSIZE*blkindex;
    }
}
 
int main() {
    ll t;
    posneg(n), posneg(q);
    
    for(ll i = 1;i<=n;i++) posneg(a[i]);
    decompose();
 
    while(q--){
        posneg(t);
        if(t==1) printf("%lld\n", getindex());
        else update();
    }
 
    return 0;
}   
