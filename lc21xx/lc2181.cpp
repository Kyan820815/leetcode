//--- Q: 2181. Merge Nodes in Between Zeros

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

//--- method 1: two pointer processing
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        auto now = head, pre = dummy;
        while (now) {
            if (!now->val) {
                now = now->next;
            } else {
                auto tmp = now;
                tmp = tmp->next;
                while (tmp && tmp->val) {
                    now->val += tmp->val;
                    tmp = tmp->next;
                }
                pre->next = now;
                pre = now;
                now = tmp;
            }
        }
        pre->next = now;
        return dummy->next;
    }
};
