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
        vector<pair<ListNode *, int>> sk;
        int len = 0, idx = 0;
        vector<int> res;
        while (head) {
            while (sk.size() && sk.back().first->val < head->val) {
                res[sk.back().second] = head->val;
                sk.pop_back();
            }
            sk.push_back({head, idx++});
            res.push_back(0);
            head = head->next;
        }
        return res;
    }
};

//--- method 2: two pass O(n) backtrack, better
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode *cur;
        stack<int> sk;
        cur = head;
        while(cur)
        {
        	res.push_back(cur->val);
        	cur = cur->next;
        }
        for (int i = res.size()-1; i >= 0 ; --i)
        {
        	while (sk.size() != 0 && sk.top() <= res[i])
        	{
        		sk.pop();
        	}
        	int val = res[i];
        	if (!sk.size())
        		res[i] = 0;
        	else
        		res[i] = sk.top();
        	sk.push(val);
        }
        return res;
    }
};