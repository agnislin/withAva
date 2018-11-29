#include<stdio.h>
#include<stdlib.h>

#define SIZE(x) sizeof(x)/sizeof(*x)
int twoSum(int *nums, int start, int end, const int pos, int ***a){
	int i = 0;
	int **s = (int**)malloc(sizeof(int*));
	
	printf("%d %d \n\n\n", start, end);
	while( start < end ){
//		if( start == pos ){
//			start++;
//			continue;
//		}
//		
//		if( end == pos ){
//			end--;
//			continue;
//		}
//		
		
		printf("%d %d \n", start, end);
		printf("%d %d %d\n",  nums[start] , nums[end] , nums[pos] );
		
		if( nums[start] + nums[end] + nums[pos] == 0 ){
			*(s+i) = (int *)malloc( sizeof(int) * 3);
			printf("====---------=======");
			printf("%d %d \n", start, end);
			printf("%d %d %d\n",  nums[start] , nums[end] , nums[pos] );
			s[i][0] =nums[pos];
			s[i][1] =nums[start++];
			s[i][2] =nums[end];
			i++;
		}else if( nums[start] + nums[end] > -nums[pos] ){
			end--;
		}else{
			start++;
		}
	}
	*a = s;
	return i;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
	int **s = (int**)malloc(sizeof(int*));
	int **a = NULL;
	int i = 0, n = 0;
	
	qsort(nums, numsSize, sizeof(int), cmp);
	for(i = 0; i < numsSize; i++){
	printf("==================");
		int t = twoSum(nums, i+1, numsSize-1, i, &a);
		
		while( t > 0 ){
			s[n++] = a[--t];
		}
		

		
		while( i+1<numsSize && nums[i] == nums[i+1] ) i++;
	}
	*returnSize = n;
	return s;
}



int main(){
	int nums[] = {-1, 0, 1, 2, -1 ,-4, 2, 4};
	int n = 0;
	int i = 0;

	int **res = threeSum(nums, SIZE(nums), &n);
	
	printf("\n==================\n");
	for(i = 0; i < n; i++){
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	}

	return 0;
}











//    for(i=0; i<numsSize; i++){
//    	for(j=0; j<3; j++){
//    		printf("")
//		}
//	}
