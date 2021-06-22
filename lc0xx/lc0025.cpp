//--- Q: 0025. Reverse Nodes in k-Group

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

//--- method 1: initialize revH as next start of reverse list 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head), *now = head, *last = dummy;
        while (now) {
            int i = 0;
            auto cur = now;
            for (i = 0; i < k && cur; ++i) {
                cur = cur->next;
            }
            if (i != k) {
                break;
            }
            ListNode *revH = cur, *nlast = now;
            while (now != cur) {
                auto tmp = now->next;
                now->next = revH;
                revH = now;
                now = tmp;
            }
            last->next = revH;
            last = nlast;
        }
        return dummy->next;
    }
};