//--- Q: 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

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

//--- method 1: linear processing
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int cnt = 1, start = -1, last = -1, find = 0;
        int mind = INT_MAX;
        auto now = head->next, prev = head;
        while (now->next) {
            if (now->val > prev->val && now->val > now->next->val || now->val < prev->val && now->val < now->next->val) {
                ++find;
                if (start == -1) {
                    start = cnt;
                }
                if (last != -1) {
                    mind = min(mind, cnt-last);
                }
                last = cnt;
            }
            prev = now;
            now = now->next;
            ++cnt;
        }
        return find < 2 ? vector<int>{-1,-1} : vector<int>{mind, last-start};
    }
};