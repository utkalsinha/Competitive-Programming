/*
Gogle code Jam Prob. 2:
Title: Tidy Numbers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 19
#define BIGINT long long

int charToDigit(char c){
	return (int)(c - '0');
}

char digitTochar(int d){
	return (char)(d + '0');
}

void solvePuzzle(char num[]){
	int forwardi = 0;
	int backwardi = 0;
	int tempdigit;
	for(;forwardi < MAX;forwardi++){
		if(charToDigit(num[forwardi])) break;
	}
	int curmax = charToDigit(num[forwardi]);
	
	for(++forwardi;forwardi<MAX;forwardi++){
		tempdigit = charToDigit(num[forwardi]);
		if(tempdigit < curmax){
			backwardi = forwardi;
			break;
		} else {
			curmax = tempdigit;
		}
	}
	// adjust forward
	for(;forwardi < MAX;forwardi++){
		// assign rest digits to 9
		num[forwardi] = digitTochar(9);
	}
	// adjust backward
	backwardi--;
	int temp_back_previ, temp_back_prev;
	for(;backwardi>= 0;backwardi--){
		tempdigit = charToDigit(num[backwardi]);
		if((backwardi -1)>= 0){
			temp_back_previ = backwardi - 1;
			temp_back_prev = charToDigit(num[temp_back_previ]);
			if(temp_back_prev == tempdigit){
				num[backwardi] = digitTochar(9);
			} else {
				// temp_prev will always be less than tempdigit
				num[backwardi] = digitTochar(tempdigit-1);
				break;	
			}	
		} else {
			num[backwardi] = digitTochar(tempdigit-1);
		}
	}
		
}

BIGINT strToBigInt(char num[]){
	BIGINT res = 0;
	BIGINT factor = 10;
	int i = 0;
	int digit;
	for(;i<MAX;i++){
		digit = charToDigit(num[i]);
		if(digit) break;
	}
	
	for(;i<MAX;i++){
		digit = charToDigit(num[i]);
		res = res*factor + digit;
	}
	
	return res;
}

void ExtractNumCharacters(char num[], BIGINT n){
	int i = MAX -1;
	char buffer[1];
	while(n){
		num[i] = digitTochar(n%10);
		n = n/10;
		i--;
	}
}

int main(){
	int T;	
	int i = 1;
	BIGINT N;
	scanf("%d",&T);
	while(i <= T){
		// get input
		scanf("%lld",&N);
		// calculate answer
		char num[MAX];
		memset(num,'0',sizeof(num));
		ExtractNumCharacters(num,N);
		solvePuzzle(num);
		printf("Case #%d: %lld\n",i,strToBigInt(num));
		i++;
	}
	
	return 0;
}


