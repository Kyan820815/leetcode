//--- Q: 206. Reverse Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode *rev = NULL;
    	recur(head, &rev);
        return rev;
    }
    void recur(ListNode *head, ListNode **rev)
    {
    	ListNode *cur;
    	if (!head) return;
    	
        cur = head;
    	head = head->next;
		cur->next = *rev;
		*rev = cur;

    	recur(head, rev);
    }
};

//--- method 2: iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *rev = NULL, *cur;

        while(head)
        {
        	cur = head;
        	head = head->next;
        	cur->next = rev;
            rev = cur;
        }
        return rev;
    }
};