#include <stdio.h>
#include <stdlib.h>

inline void fastint(int *x){
	register int c = getchar();
	int t = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar());
		for(; c>47 && c<58 ; c = getchar()){
			t = (t<<1) + (t<<3) + c - 48;
		}
	*x = t;
}
inline void faststring(char * arr){
	register char c = getchar();
	register int i = 0;
 	while (c < 33)
 		c = getchar();
	while (c != '\n' && c != EOF){
		arr[i] = c;
		c = getchar();
		i = i + 1;
	}
		arr[i] = '\0';
}
inline void printresult(int * res, int * j){
	char *buffer =(char *) malloc(1000001 * sizeof(char));
	register int x = *j,i=0,z=0;
	int num =0,rem =0;
	while(x--){
		z=0;
		num = res[i];
		if(num== 0){
			putchar('0');
			putchar('\n');
			i++;
		}
		else{
			while(num != 0){
				rem = num % 10;    // base 10 number
				buffer[z] = rem + '0'; 
				z++;
				num = num/10;
			}
    		while (z--){    // printing in reverse order
        		putchar(buffer[z]);
   	 		}			
			putchar('\n');
			i++;
		}		
	}
	free(buffer);		
}

int main(){
 	int tc, depth, result,T;  // tc is for total count
	char* arr;
	char c;
	int i=0, *res,z = 0;
	fastint(&T);	
	arr =(char *) malloc(1000001 * sizeof(char));
	res = (int *)malloc(501*sizeof(int));
	while(T--){
		tc = 0, depth = 0,result =0,i=0;
		faststring(arr);	
		c = arr[i];
		for(;c;){			
			if(c == 60){
				if(depth<500001){
					tc++;
					depth++;
				}else break;
			}
			else{
				tc++;
				depth--;
				if(depth==0)result=tc;
				else if(depth<0)break;
			}
			i++;
			c = arr[i];		
		}
		res[z] = result;		
		z++;
	}
    printresult(res, &z);
	free(arr);
	free(res);
	return 0;
}