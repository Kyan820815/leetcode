//--- Q: 0142. Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: slow & fast pointer, better
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        bool cycle = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle = true;
                break;
            }
        }
        if (!cycle) {
            return NULL;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};