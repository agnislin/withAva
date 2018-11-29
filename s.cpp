#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>

/*
start i=1, j=1

if word1[i] == word2[j]
	dp[i][j] = dp[i-1][j-1]
else
	insert:	 dp[i][j] = dp[i][j-1] + 1
	replace: dp[i][j] = dp[i-1][j-1] + 1
	delete:  dp[i][j] = dp[i-1][j] + 1

horse -> ros
		h	o	r	s	e
	0	1	2	3	4	5
r	1	1	2	2	3	4
o	2	2	1	2	3	4
s	3	3	2	2	2	3
*/
int min(int a, int b, int c){
	return a < b? (a < c? a: c): b;
}

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1) + 1;
    int len2 = strlen(word2) + 1;
    
    int dp[len1][len2] = {0};
    int i, j, k;
    
    memset( dp, 0, len1 *len2 );
	for(i=0; i<len1; i++){
		dp[i][0] = i;
	}
    for(i=0; i<len2; i++){
    	dp[0][i] = i;
	}

    for(i=1; i<len1; i++){
        for(j=1; j<len2; j++){
            if( word1[i-1] == word2[j-1] ){
            	dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = min( dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1 );
			}
        }
    }
    return dp[len1-1][len2-1];
}


int main(){
	char* word1 = "teacher";
	char* word2 = "detacher";
	printf("%d", minDistance(word1, word2));
	return 0;
}
















//	char* word1 = "teacher";
//	char* word2 = "detacher";
//
//
//		t	e	a	c	h	e	r
//	0	1	2	3	4	5	6	7
//d	1		
//e	2
//t	3
//a	4
//c	5
//h	6
//e	7
//r	8
//
//























