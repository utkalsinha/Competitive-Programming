/*
By carefully studying the given series it is found that there are 3 A.P. series of 1, 2, and 3 with a common difference of 6 in each of the series.
So at a time the chef could be in any one of these series or none at all. Hence, to find if the chef falls in the given input position number,
we just have to check if the given input number is a term in anyone of the three series. And this could be done in linear time, 
i.e., in O(n) time complexity. 
*/

#include <stdio.h>

int main(){
	long long input = 0;
	
	scanf("%lld", &input);
	
	if((input + 5)%6 == 0 )  		// To check if the input is a term in the series 1
		printf("yes");
	else if((input + 3)%6 == 0 )	// To check if the input is a term in the series 2
		printf("yes");
	else if(input % 6 == 0 )		// To check if the input is a term in the series 3
		printf("yes");
	else printf("no");				// THe given input number does not belong to any series and hence the chef will not fall in this particular position.
	
	return 0;
}
