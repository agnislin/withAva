/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:
	
	Insert a character
	Delete a character
	Replace a character
	
Example 1:
	Input: word1 = "horse", word2 = "ros"
	Output: 3
	Explanation: 
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')
	
Example 2:
	Input: word1 = "intention", word2 = "execution"
	Output: 5
	Explanation: 
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')

*/

#include<stdio.h>
#include<string.h>

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
	int m = a < b? a: b;
	return m < c? m: c;
}

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    int dp[len1 + 1][len2 + 1];
    int i, j;
    
    
	for(i=0; i<=len1; i++){
		dp[i][0] = i;
	}
    for(i=0; i<=len2; i++){
    	dp[0][i] = i;
	}

    for(i=1; i<=len1; i++){
        for(j=1; j<=len2; j++){
            if( word1[i-1] == word2[j-1] ){
            	dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = min( dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1 );
			}
        }
    }
    return dp[len1][len2];
}


int main(){ 
	char* word1 = "horse";
	char* word2 = "ros";
	printf("%d", minDistance(word1, word2));
	return 0;
}
