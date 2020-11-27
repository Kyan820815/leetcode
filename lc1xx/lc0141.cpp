//--- Q: 141. Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: slow, fast pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        	if (!fast || !fast->next || slow == fast)
        	    break;
        }
        return  (!fast || !fast->next) ? false: true;
    }
};