//--- Q: 203. Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: linear time operation with pre, cur
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode *pre, *cur, *dummy = new ListNode(-1);
    	dummy->next = head, pre = dummy, cur = head;
    	while (cur)
    	{
    		if (cur->val == val)
    			pre->next = cur->next;
    		else
    			pre = cur;
    		cur = cur->next;
    	}
    	return dummy->next;
    }
};