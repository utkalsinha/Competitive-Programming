#include <stdio.h>

int main(){
	for(int m = 131072;m<262144;m++){
		printf("Position m: %d = ", m);
		for(int n = 0;n<20000;n++){
			if((~(m+n) & n) != 0){
				//printf("_");
			}
			else printf("%d, ", n);
		}
		printf("\n");
	}
	
	return 0;
}
