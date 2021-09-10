//--- Q: 0725. Split Linked List in Parts

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: link list operation
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        auto now = head;
        while (now) {
            now = now->next;
            ++len;
        }
        int rem = len%k, group = len/k;
        vector<ListNode *> res;
        now = head;
        while (k--) {
            res.push_back(now);
            if (!now) {
                continue;
            }
            int sz = group + (rem-- > 0);
            ListNode *pre;
            while (sz--) {
                pre = now;
                now = now->next;
            }
            pre->next = nullptr;
        }
        return res;
    }
};