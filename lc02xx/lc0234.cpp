//--- Q: 234. Palindrome Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: O(1) space & O(n) time
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast, *mid, *now, *rev = NULL;
        int even;

        if (!head || !head->next)
        	return true;
        slow = fast = head;

        while(fast && fast->next)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        if (!fast) even = 1;
        else if (!fast->next) even = 0;
        
        mid = slow;
        if (even)
        	fast = mid;
    	else
    		fast = mid->next;
        slow = head;

    	while(slow != mid)
    	{
    		now = slow;
    		slow = slow->next;
    		now->next = rev;
    		rev = now;
    	}
        while(fast)
        {
        	if (rev->val != fast->val)
        		return false;
        	fast = fast->next;
        	rev = rev->next;
        }
        return true;
    }
};

//--- method 2: magic solution, O(n) space & O(n) time
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       return dfs(&head, head);
    }
    bool dfs(ListNode** left, ListNode *right)
    {
    	bool isPal;
    	if (!right) return true;
    	isPal = dfs(left, right->next);
    	if (isPal && ((*left)->val == right->val))
    		isPal = true;
    	else
    		isPal = false;
    	*left = (*left)->next;
    	return isPal;
    }
};
