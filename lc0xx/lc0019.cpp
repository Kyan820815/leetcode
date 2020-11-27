//--- Q: 019. Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: process fast of n first, then process fast & slow together, better
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* fast = head, *slow = head;
    	for (int i = 0; i < n; i++)
    		fast = fast->next;
    	if (!fast) return head->next;

    	while(fast->next != NULL)
    	{
    		fast = fast->next;
    		slow = slow->next;
    	}
    	slow->next = slow->next->next;
		return head;
	}
};

//--- method 2: run first to find len then find len-n
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* cur = head;
		int len = 0;
		while (cur)
		{
			len++;
			cur = cur->next;
		}
		len = len-n;
		if (len == 0) return head->next;
		cur = head;
		for (int i = 0; i < len-1; ++i)
			cur = cur->next;
		cur->next = cur->next->next;
		return head;
	}
};