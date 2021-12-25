//--- Q: 0817. Linked List Components

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: one pass O(n)
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        ListNode *now = head;
        int res = 0;
        while (now) {
            res += set.find(now->val) != set.end() && (!now->next || set.find(now->next->val) == set.end());
            now = now->next;
        }
        return res;
    }
};