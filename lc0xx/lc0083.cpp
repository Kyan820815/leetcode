//--- Q: 83. Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: link list operation
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur, *dummy = new ListNode(-1), pre;
        dummy->next = head;
        pre = dummy, cur = head;
        while (cur)
        {
        	if (cur->next && cur->val == cur->next->val)
        	{
    	    	while (cur->next && cur->val == cur->next->val)
	        		cur = cur->next;
	        	pre->next = cur;
        	}
        	pre = cur;
        	cur = cur->next;
        }
        return dummy->next;
    }
};