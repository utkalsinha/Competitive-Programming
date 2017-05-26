/*
  Problem	:	SnackDown 2017 - SAMESNAK (https://www.codechef.com/SNCKQL17/problems/SAMESNAK)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <stdio.h>
typedef long long int BIG;

typedef struct point{
	BIG x;
	BIG y;
} POINT;

static inline BIG max(BIG a, BIG b){ return (a>b)?a:b;}
BIG min(BIG a, BIG b){ return (a>b)?b:a;}

static inline int isIntersectAtCorner(POINT p1, POINT p2, POINT p3, POINT p4){
	if((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) || (p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) return 1;
	else return 0;
}

static int check_on_line_segment(POINT p, POINT q, POINT r){
	if(q.x <= max(p.x,r.x) && q.x >= min(p.x,r.x) && q.y <= max(p.y,r.y) && q.y >= min(p.y,r.y)) return 1;
	else return 0;
}

static int check_orientation(POINT p, POINT q, POINT r){
	BIG ori = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
	if(!ori) return 0;
	return (ori>0)?1:2;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		POINT p1,p2,p3,p4;
		scanf("%lld",&p1.x),scanf("%lld",&p1.y),scanf("%lld",&p2.x),scanf("%lld",&p2.y);
		scanf("%lld",&p3.x),scanf("%lld",&p3.y),scanf("%lld",&p4.x),scanf("%lld",&p4.y);
		int d1,d2,d3,d4;
		d1 = check_orientation(p1,p2,p3);
		d2 = check_orientation(p1,p2,p4);
		d3 = check_orientation(p3,p4,p1);
		d4 = check_orientation(p3,p4,p2);
		if(d1 != d2 && d3 != d4) {
			if(isIntersectAtCorner(p1,p2,p3,p4))printf("yes\n");
			else printf("no\n");	
		}
		else{
			// Points are collinear. Handle special cases.
			if(d1 == 0 && check_on_line_segment(p1,p3,p2))printf("yes\n");
			else if(d2 == 0 && check_on_line_segment(p1,p4,p2))printf("yes\n");
			else if(d3 == 0 && check_on_line_segment(p3,p1,p4))printf("yes\n");
			else if(d4 == 0 && check_on_line_segment(p3,p2,p4))printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
