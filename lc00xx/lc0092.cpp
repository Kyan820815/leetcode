//--- Q: 0092. Reverse Linked List II
//--- last written: 2023/07/08

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: reverse linked list from the next node of right-th node
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head), *cur = head, *pre = dummy;
        dummy->next = head;
        int idx;
        for (idx = 1; idx < left; ++idx) {
            pre = cur;
            cur = cur->next;
        }
        auto now = cur;
        for (idx = left; idx <= right; ++idx) {
            now = now->next;
        }
        ListNode *revH = now;
        while (cur != now) {
            auto tmp = cur->next;
            cur->next = revH;
            revH = cur;
            cur = tmp;
        }
        pre->next = revH;
        return dummy->next;
    }
};
