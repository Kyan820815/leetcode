//--- Q: 1019. Next Greater Node In Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: one pass better
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, sk, nums;
        auto now = head;
        int idx = -1;
        while (now) {
            while (sk.size() && nums[sk.back()] < now->val) {
                res[sk.back()] = now->val;
                sk.pop_back();
            }
            sk.push_back(++idx);
            res.push_back(0);
            nums.push_back(now->val);
            now = now->next;
        }
        return res;
    }
};

//--- method 2: two pass back tracking stack
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, sk;
        auto now = head;
        while (now) {
            res.push_back(now->val);
            now = now->next;
        }
        for (int i = res.size()-1; i >= 0; --i) {
            while (sk.size() && sk.back() <= res[i]) {
                sk.pop_back();
            }
            int nodeval = res[i];
            res[i] = sk.size() ? sk.back() : 0;
            sk.push_back(nodeval);
        }
        return res;
    }
};