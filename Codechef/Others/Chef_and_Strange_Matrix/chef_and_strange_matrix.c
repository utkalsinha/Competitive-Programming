#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node{
	int key;
	int value;
	struct node *ptr;
} NODE;

inline int getcount(NODE *hashtable,int *x,int *y){ 
	NODE *temp = &hashtable[*x];
	if(temp->ptr == NULL){
		return 0;
	}
	else{
		while(temp->ptr != NULL){
			temp = temp->ptr;
			if(temp->key == *y){
				return temp->value;
			}
		}
		return 0;
	}
}
int main(){
	int n,m,p,x,y,z,i=0,j=0,flag = 0,start_set=0;
	NODE *temp;
	
	scanf("%d %d %d",&n,&m,&p);
	
	NODE *hashtable = (NODE *)malloc(n* sizeof(NODE));  // create the index array
	for(i=0;i<n;i++){
		hashtable[i].key =0;
		hashtable[i].value = 0;
		hashtable[i].ptr = NULL;
	}

	
	for(i=0;i<p;i++){     // record the number of updates
		flag = 0;
		scanf("%d %d",&x,&y);
		temp = &hashtable[x-1];
		if(temp->ptr == NULL){
			if(temp->key == y){
				temp->value = temp->value + 1;
			}
			else{
				temp->ptr = (NODE *)malloc(sizeof(NODE));
				temp->ptr->key = y;
				temp->ptr->value = 1;
				temp->ptr->ptr = NULL;
			}
		}
		else{
			while(temp->ptr != NULL){
					
				if(temp->key == y){
					temp->value = temp->value + 1;
					flag = 1;
					break;
				}
				else{
					temp = temp->ptr;	
				}
			
			}
			if(flag == 0){
				if(temp->key==y){
					temp->value = temp->value + 1;
				}
				else{
					temp->ptr = (NODE *)malloc(sizeof(NODE));
					temp->ptr->key = y;
					temp->ptr->value = 1;
					temp->ptr->ptr = NULL;
				}			
			}	
		}		
	}		
	// start calculating and printing the cost
	int result,tmp_count,skip_flag, early_count; // to store the cost
	int no_counts,p_count = p, p_count_flag; // to count the number of counts of a co-ordinate
	for(i=0;i<n;i++){
		skip_flag = 0;
		result = -1;
		early_count = 0;
		p_count_flag = 0;
		no_counts = getcount(hashtable,&i,&m);
		tmp_count = no_counts;
		early_count = no_counts;
		if(no_counts){
			p_count--;
		}
		if((p_count <= 0 ) && (m > 1)){
			printf("%d\n",result);
		}
		else{
			for(j=m-1;j>1;j--){
				no_counts = getcount(hashtable,&i,&j);
				if(no_counts) p_count--;
				if((no_counts) <= (early_count + 1)){
					if(p_count <= 0){
						p_count_flag = 1;
						break;
					}
				}
				else{
					result = -1;
					skip_flag = 1;
					break;
				}
				early_count = no_counts;			
			}
			if(!skip_flag){
				no_counts = getcount(hashtable,&i,&j);
				if(no_counts) p_count--;
				if((no_counts) <= (early_count + 1)){
					result = m + tmp_count - 1 - no_counts;
				}
				else{
					result = -1;
				}
					
			}
			if(p_count_flag){
				result = m + tmp_count - 1;
			}
			if((m==1)&&(n==1))
				result++;
			printf("%d\n",result);			
		}

	}
	// End calculating and printing the costs
	free(hashtable); // free all the dynamically allocated memory
	return 0;
}