//--- Q: 369. Plus One Linked List

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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *now = head, *last_non_nine = dummy;
        while (now) {
            if (now->val != 9) {
                last_non_nine = now;
            }
            now = now->next;
        }
        last_non_nine->val += 1;
        now = last_non_nine->next;
        while (now) {
            now->val = 0;
            now = now->next;
        }
        return last_non_nine == dummy ? last_non_nine : dummy->next;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int val = dfs(head);
        if (val) {
            ListNode *nh = new ListNode(val);
            nh->next = head;
            return nh;
        }
        return head;
    }
    int dfs(ListNode *now) {
        if (!now->next) {
            now->val += 1;
        } else {
            int val = dfs(now->next);
            now->val += val;
        }
        int q = now->val / 10;
        now->val %= 10;
        return q;
    }
};