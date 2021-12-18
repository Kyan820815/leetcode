//--- Q: 2095. Delete the Middle Node of a Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//--- method 1: slow fast pointer
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *slow = head, *fast = head, *prev = dummy;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return dummy->next;
    }
};