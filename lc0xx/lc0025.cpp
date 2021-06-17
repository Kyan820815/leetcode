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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *now = head, *prev = dummy;
        dummy->next = head;
        while (now) {
            ListNode *tmp = now;
            for (int i = 0; i < k; ++i) {
                if (!tmp) {
                    return dummy->next;
                }
                tmp = tmp->next;
            }
            ListNode *revH = tmp, *last_now = now;
            while (now != tmp) {
                ListNode *next_n = now->next;
                now->next = revH;
                revH = now;
                now = next_n;
            }
            prev->next = revH;
            prev = last_now;
        }
        return dummy->next;
    }
};