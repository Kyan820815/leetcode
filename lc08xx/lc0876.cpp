//--- Q: 0876. Middle of the Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: slow fast pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        return slow;
    }
};