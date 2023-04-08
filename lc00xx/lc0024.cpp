//--- Q: 0024. Swap Nodes in Pairs
//--- last written: 2023/03/11

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: linklist composition
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head), *last = dummy, *now = head;
        while (now && now->next) {
            auto next_now = now->next->next;
            last->next = now->next;
            now->next->next = now;
            now->next = next_now;
            last = now;
            now = next_now;
        }
        return dummy->next;
    }
};
