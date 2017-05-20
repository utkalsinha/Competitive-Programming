/*
  Problem	:	HackerRank Contest - Week of Code 32 (Duplication - https://www.hackerrank.com/contests/w32/challenges/duplication)
  Author	: 	Utkal Sinha
  Contact	: 	info@utkalsinha.com
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	/*  
		// Below is the code to generate the required inverted extended string.
		// Once obtained we can use this generated string to quickly access the value.
		string str = "0",str1;
		int len = 1;
		while(len <=1000){
			str1 = "";
			for(int j = 0;j<len;j++){
				if(str[j] == '0')str1 += "1";
				else str1 += "0";
			}
			str += str1;
			len = str.length();
		}
		for(int i = 0;i<str.length();i++){
			printf("%c",str[i]);
		}
	*/
	string str = "0110100110010110100101100110100110010110011010010110100110010110100101100110100101101001100101100110100110010110100101100110100110010110011010010110100110010110011010011001011010010110011010010110100110010110100101100110100110010110011010010110100110010110100101100110100101101001100101100110100110010110100101100110100101101001100101101001011001101001100101100110100101101001100101100110100110010110100101100110100110010110011010010110100110010110100101100110100101101001100101100110100110010110100101100110100110010110011010010110100110010110011010011001011010010110011010010110100110010110100101100110100110010110011010010110100110010110011010011001011010010110011010011001011001101001011010011001011010010110011010010110100110010110011010011001011010010110011010010110100110010110100101100110100110010110011010010110100110010110100101100110100101101001100101100110100110010110100101100110100110010110011010010110100110010110011010011001011010010110011010010110100110010110100101100110100110010110011010010110100110010110";
	int q,x;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		printf("%c\n",str[x]);
	}
	return 0;
}



