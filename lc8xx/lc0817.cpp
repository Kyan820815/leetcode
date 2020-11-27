//--- Q: 817. Linked List Components

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1-1: one pass O(n)
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> set(G.begin(), G.end());
        int res = 0;
        bool on = false;
        while (head) {
            if (set.find(head->val) != set.end()) {
                on = true;
            } else if (on) {
                ++res;
                on = false;
            }
            head = head->next;
        }
        return on ? res+1 : res;
    }
};

//--- method 1-2: one pass O(n)
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> set;
        ListNode *dummy = new ListNode(-1), *now = head, *last = dummy;
        dummy->next = now;
        int res = 0;
        for (int i = 0; i < G.size(); ++i)
            set.insert(G[i]);
        while (now) {
            if (set.find(last->val) == set.end() && set.find(now->val) != set.end())
                ++res;
            last = now;
            now = now->next;
        }
        return res;
    }
};