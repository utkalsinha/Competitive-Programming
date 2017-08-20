/*
  Problem 	: Codechef August - 2017- https://www.codechef.com/AUG17/problems/PALINGAM
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/
 
#include<stdio.h>
#include <string.h>
#define gc getchar
 
int rin() { char c = gc(); while(c<'0' || c>'9') c = gc(); int ret = 0; while(c>='0' && c<='9') { ret = 10 * ret + c - 48; c = gc(); } return ret; }
 
int main() {
    char c;
    int index, ac[26], bc[26];
    int T = rin();
    
    while(T--){
        int awillwin = 0, oneway = 0, revway = 0;
        memset(ac, 0, sizeof(ac));
        memset(bc, 0, sizeof(bc));
        
        while((c = gc()) != '\n'){
            index = c-'a';
            ac[index]++;
        }
        
        while((c = gc()) != '\n'){
            index = c-'a';
            bc[index] = 1;
        }
        
        for(int i = 0;i<26;i++){
            if(ac[i]>1 && !bc[i]) {
                awillwin = 1;
            }
            if(ac[i]==1 && !bc[i]) oneway = 1;
        }
        
        if(awillwin) printf("A\n");
        else {
            if(!oneway) printf("B\n");
            else {
                for(int i = 0;i<26;i++){
                    if(bc[i] && !ac[i]){
                        revway = 1;
                        break;
                    }
                }
                if(!revway) printf("A\n");
                else printf("B\n");
            }
        }
    }
    
    return 0;
}
