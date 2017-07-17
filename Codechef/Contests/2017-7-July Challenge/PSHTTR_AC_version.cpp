/*
  Problem 	: Codechef - July Challenge 2017 - PSHTTR - https://www.codechef.com/JULY17/problems/PSHTTR
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define USEWINDOWS 1 // change this value to 0 before submitting online. 1 for developing on Windows platform
#if !USEWINDOWS
#define gc getchar_unlocked
#else
#define gc getchar
#endif

#define pb push_back
#define mp make_pair
#define N 131072

int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }

int up_v, depth[N],temp_f[N], count_main, L,R,C, sumv, verts[N<<1], l[N] ,r[N], count1, ans[N];

typedef struct { int tu, tv, tn, c;} NODE;
typedef struct { int u,v,c,pos; } NODE_2;

NODE_2 gor[N];
NODE edges[N<<1], edges_c[N<<1];

bool edge_comp(NODE u,NODE v){ return u.c > v.c; }
bool edge_comp_less(NODE_2 u, NODE_2 v){ return u.c < v.c; }

void add_data(int u,int v,int cost){
	count1++;
	edges[count1].tv=u; 
	edges[count1].tu=v; 
	edges[count1].c=cost;
	edges[count1].tn=temp_f[u];
	temp_f[u] = count1;
}
void add_data_twice(int u,int v, int cost){
	add_data(u,v,cost);
	add_data(v,u,cost);
}
void init(){
    L = R = C = count1 = count_main = sumv = 0;
    memset(depth,0,sizeof(depth));
	memset(temp_f,0,sizeof(temp_f));
	memset(verts,0,sizeof(verts));
	depth[1] = 1;
}
void step_lower(int l,int r, int u){
    int k;
	if(l == r) return;
    k = verts[u]; 
	verts[u] = 0;
    verts[u<<1] = verts[u<<1] ^ k; 
	verts[u<<1|1] = verts[u<<1|1] ^ k;
}
int searchv(int l, int r, int u, int k){
    if(l == r) {
    	return verts[u];
	}
    int mid = (l+r)>>1;
    if(verts[u]) {
    	step_lower(l,r,u);
	}
    if(k <= mid) {
    	return searchv(l,mid,u<<1,k);
	}
    else {
    	return searchv(mid+1,r,(u<<1|1),k);
	}
}
void pushRec(int l,int r, int u){
    if(L<=l && r<=R){ 
		verts[u] = verts[u] ^ C; 
		return;
	}
    if(l==r) return;
    if(verts[u]) {
    	step_lower(l, r, u);
	}
    int mid = (l+r)>>1;
    if(L<=mid) {
    	pushRec(l,mid, (u<<1));
	}
    if(R>mid) {
    	pushRec(mid+1,r, (u<<1|1));
	}
}
void DFS(int u){
	//printf("> 1==== Debug message\n");
    l[u] = ++sumv;
    for(int i = temp_f[u]; i ; i = edges[i].tn){
        int curNode = edges[i].tu;
        if(!depth[curNode]) {
        	depth[curNode] = depth[u]+1;
			DFS(curNode);
		}
    }
    r[u] = sumv;
}

int main()
{
	int T,n,m,u,v,c, q_cost, l_sum, r_sum;
    T = rin();
    while(T--){
        init();
        n=rin();
		for(int i=1; i<n; i++){
            u = rin(), v = rin(), c = rin();
			add_data_twice(u, v, c);
            count_main++;
			edges_c[count_main].tu=v; 
			edges_c[count_main].tv=u; 
			edges_c[count_main].c=c;
        }
        DFS(1);
		up_v = count_main; 
		sort(edges_c+1,edges_c+1+count_main,edge_comp);
        
		m=rin(); 
		for(int i = 1; i <= m; i++) {
			gor[i].pos = i;
			gor[i].u = rin();
			gor[i].v=rin();
			gor[i].c=rin();
		}
        sort(gor+1,gor+1+m,edge_comp_less);
        
		for(int i = 1; i <= m; i++){
            q_cost = gor[i].c;
            while(up_v && (edges_c[up_v].c <= q_cost)){
                u=edges_c[up_v].tv;
				v=edges_c[up_v].tu;
				c=edges_c[up_v].c;
                up_v--;
                if(depth[u] < depth[v]) {
                	swap(u,v);
				}
                L = l[u];
				R = r[u];
				C = c;
                pushRec(1,n,1);
            }
            
            l_sum = searchv(1, n, 1, l[gor[i].u]);
			r_sum = searchv(1, n, 1, l[gor[i].v]);
            ans[gor[i].pos] = l_sum ^ r_sum;
        }
        
        for(int i = 1; i <= m; i++) {
        	printf("%d\n",ans[i]);
		}
    }
    return 0;
}

