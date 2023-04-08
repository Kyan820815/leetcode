//--- Q: 0061. Rotate List
//--- last written: 2023/03/16

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: linklist operation
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *dummy = new ListNode(-1, head), *now = head, *pre = dummy;
        while (now) {
            pre = now;
            now = now->next;
            ++len;
        }
        pre->next = head;
        if (!len) {
            return NULL;
        }
        k = len-k%len;
        now = dummy;
        while (k--) {
            now = now->next;
        }
        auto nh = now->next;
        now->next = NULL;
        return nh;
    }
};
