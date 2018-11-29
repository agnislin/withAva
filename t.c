/*
	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
	
	Example:
	
	Input:
	[
	  1->4->5,
	  1->3->4,
	  2->6
	]
	Output: 1->1->2->3->4->4->5->6

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 

#include<stdio.h>
#include<stdlib.h>
 
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
}


struct ListNode * insert(struct ListNode *L, int val){
	struct ListNode *p = L;
	
	if( p == NULL ){
		p = malloc( sizeof(struct ListNode) );
		L = p;
	}else{
		while( p != NULL ){
			p = p->next;
		}
		p = malloc( sizeof(struct ListNode) );
	}
	p->val = val;
	p->next = NULL;
	return L;
}

int main(void){
	struct ListNode * list = NULL;
	
	list = insert(list, 10);
	printf("f");
	list = insert(list, 29);
	printf("f");
	list = insert(list, 39);
	
	printf("f");
	
	
	printf("%d", list->next->next->val);
	return 0;
}
