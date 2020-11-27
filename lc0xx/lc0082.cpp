//--- Q: 082. Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: delete duplicate number
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode *dummy = new ListNode(-1);
    	ListNode *pre, *now;
    	int same = 0;

    	dummy->next = head;
    	pre = dummy;
    	now = head;

		while(now && now->next)
		{
			if (now->next->val == now->val)
    			same = 1;
    		else
    		{
    			if (same)
    			{
    				pre->next = now->next;
    				same = 0;
    			}
    			else
    				pre = now;
    		}
    		now = now->next;
		}
		if (same)
    		pre->next = now->next;
    	return dummy->next;
	}
};