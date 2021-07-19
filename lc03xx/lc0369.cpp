//--- Q: 0369. Plus One Linked List

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

//--- method 1: O(1) space, two pointer
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *dummy = new ListNode(0, head), *lastnot9 = dummy;
        for (auto now=head; now; now=now->next) {
            if (now->val != 9) {
                lastnot9 = now;
            }
        }
        ++lastnot9->val;
        for (auto cur=lastnot9->next; cur; cur=cur->next) {
            cur->val = 0;
        }
        return lastnot9 == dummy ? dummy : dummy->next;
    }
};