#include <stdio.h>
#include <string.h>

#define maxv 2001

void solve(){
	int i,j, ans,match_count,len;
	char s[maxv];
	scanf("%s",s);
	len = strlen(s);
	ans = 0;
	for(i = 0;i<len;){
		match_count = 0;
		for(j = i;j<len;j++){
			if(s[j] == '1' && (j+1)<len && s[j+1] =='0') {
				match_count = 2;
				j++;
				j++;
				break;	
			}
		}
		for(;j<len;j++){
			if(s[j]=='1'){
				match_count++;
				break;
			}else if(s[j] != '0'){
				match_count = 0;
				break;
			}
		}
		if(match_count == 3) ans++;
		i = j;
	}
	
	printf("%d\n",ans);	
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	
	return 0;
}
