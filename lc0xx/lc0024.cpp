//--- Q: 24. Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: linklist composition
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *last, *prev, *now;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        last = dummy;
        prev = last->next;
        if (!prev) return dummy->next;
        now = prev->next;
        while(now)
        {
        	prev->next = now->next;
        	now->next = prev;
        	last->next = now;
        	last = prev;
        	prev = prev->next;
        	if (!prev) return dummy->next;
        	now = prev->next;
        }
        return dummy->next;
    }
};