//--- Q: 0147. Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: O(1) space insertion sort
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head), *pre = dummy, *cur = head;
        while (cur) {
            auto now = dummy;
            while (now->next != cur && now->next->val <= cur->val) {
                now = now->next;
            }
            if (now->next->val > cur->val) {
                pre->next = cur->next;
                cur->next = now->next;
                now->next = cur;
            } else {
                pre = cur;
            }
            cur = pre->next;
        }
        return dummy->next;
    }
};