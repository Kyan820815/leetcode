//--- Q: 1836. Remove Duplicates From an Unsorted Linked List

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


//--- method 1: linked list operation
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        vector<int> cnt(100001, 0);
        ListNode *now = head, *dummy = new ListNode(-1, head), *last = dummy;
        while (now) {
            ++cnt[now->val];
            now = now->next;
        }
        now = head;
        while (now) {
            if (cnt[now->val] > 1) {
                last->next = now->next;
            } else {
                last = now;
            }
            now = now->next;
        }
        return dummy->next;
    }
};