/*
  Problem 	: Codechef - July Challenge - 2017 - NITIKA - https://www.codechef.com/JULY17/problems/NITIKA
  Author 	: Utkal Sinha
  Contact 	: info@utkalsinha.com
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
//#define gc getchar_unlocked
#define gc getchar

int fastRead_int() { register int c = gc(); int x; x = 0; int neg = 0; for(; ((c<48 || c>57) && c != '-'); c = gc()); if(c=='-') { neg = 1; c = gc(); } for(; c>47 && c<58 ; c = gc()) {x = (x<<1) + (x<<3) + c - 48;} if(neg) x = -x; return x;}
 
int main(){
	int T;
	T = fastRead_int();
	char str[32];
	int num,i,len;
	while(T--){
		num = 0;
		i = 0;
		gets(str);
		len = strlen(str);
		while(i<len){
			if(str[i] == ' ') num++;
			i++;
		}
		if(num == 0){
			i=0;
			putchar(toupper(str[0]));
			for(i = 1;i<len;i++){
				putchar(tolower(str[i]));
			}
			putchar('\n');
		} else if(num==1){
			i=0;
			putchar(toupper(str[0]));
			putchar('.');
			putchar(' ');
			i = 1;
			while(str[i] != ' ') i++;
			i++;
			putchar(toupper(str[i]));
			for(i = i+1;str[i]!= '\0';i++){
				putchar(tolower(str[i]));
			}
			putchar('\n');
		} else{
			i=0;
			putchar(toupper(str[0]));
			putchar('.');
			putchar(' ');
			while(str[i] != ' ') {
				i++;
			}
			i++;
			putchar(toupper(str[i]));
			putchar('.');
			putchar(' ');
			while(str[i] != ' ') i++;
			i++;
			putchar(toupper(str[i]));
			for(i = i+1;i<len;i++){
				putchar(tolower(str[i]));
			}
			putchar('\n');
		}
	}
		
	
	return 0;
} 
