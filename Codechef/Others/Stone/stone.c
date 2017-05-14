#include <stdio.h>

int main(){
	long long int A[100000],K,largest =0, new_largest = 0;
	long N, i;							
	int z = 0;


	scanf("%ld %lld",&N,&K);
	for(i=0;i<N;i++){
		scanf("%lld",&A[i]);
		if(largest < A[i])
			largest = A[i];
	}
		
	
	if(K==0){
	}
	else if(K % 2 == 0){

			
			for ( i = 0; i < N; i++ ){
				A[i] = largest - A[i];
				if(new_largest < A[i])
					new_largest = A[i];	
			}
			largest = new_largest;
			for ( i = 0; i < N; i++ ){
				A[i] = largest - A[i];	
			}	

		
	}
	else{

		for ( i = 0; i < N; i++ ){		
				A[i] = largest - A[i];	
		}	
	}
	// Start for formated printing
	for(i=0;i<N;i++){
		if(i == (N-1)){
			printf("%lld",A[i]);	
		}			
		else
			printf("%lld ",A[i]);
	}
	// End for formated printing
	
	return 0;
}