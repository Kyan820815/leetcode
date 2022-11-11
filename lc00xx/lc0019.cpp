//--- Q: 0019. Remove Nth Node From End of List
//--- last written: 2022/11/02

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: go n steps then go together
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1, head), now = head, cur = dummy;
        while (n--) {
            now = now->next;
        }
        while (now) {
            now = now->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};
