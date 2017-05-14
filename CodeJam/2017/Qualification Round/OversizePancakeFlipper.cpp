/*
Gogle code Jam Prob. 1:
Title: Oversized Pancake Flipper
*/

#include <stdio.h>
#include <string.h>

#define MAX 1500
#define IMPOSSIBLE -1
#define FOR(a,b) for(int i = a;i<b;i++)
char S[MAX];

int negativeIndex(char s[], int len){
	int resIndex = -1;
		
	for(int i = 0;i<len;i++){
		if(s[i] == '-'){
			resIndex = i;
			break;
		}			
	}	



	return resIndex;	
}

int checkAllPositive(char s[]){
	int res = 1;
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] == '-'){
			res = 0;
			break;
		}
		i++;
	}
	return res;	
}

int checkAllNegetive(char s[]){
	int res = 1;
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] == '+'){
			res = 0;
			break;
		}
		i++;
	}
	return res;	
}

int get_min_num_use(char s[], int k){
	int result = IMPOSSIBLE;
	int slen = strlen(s);
	// check for all positive
	if(strlen(s) == k){
		if(checkAllPositive(s)) return 0;
		else if(checkAllNegetive(s)) return 1;
		else return IMPOSSIBLE;
	}
	else if(strlen(s) < k) {
		if(checkAllPositive(s)) return 0;
		else return IMPOSSIBLE;
	}
	else {
		// solve and find the answer
		int continue_looping = 1;
		int z; 
		
		result++;
		while(continue_looping){
			z = negativeIndex(s,slen);
			if(z == -1) {
				break;
			} else {
				if((z+k)<= slen){
					// flip k consecutive positions
					for(int j = 0;j<k;j++){
						s[j+z] = ((s[j+z] == '-')? '+' : '-');
					}
					result++;
				} else {
					return IMPOSSIBLE;
				}
			}
		}
	}	
	
	
	return result;
}

int main(){
	int T;	
	int K;
	int res;
	int i = 1;	
	scanf("%d",&T);
	while(i <= T){
		// get input
		scanf("%s %d",S,&K);
		// calculate answer
		res = get_min_num_use(S,K);
		if(res == IMPOSSIBLE) printf("Case #%d: IMPOSSIBLE\n",i);
		else printf("Case #%d: %d\n",i,res);
			
		i++;
	}
	
	return 0;
}


