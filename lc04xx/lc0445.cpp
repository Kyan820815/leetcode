//--- Q: 0445. Add Two Numbers II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: recursion
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = countlen(l1);
        int len2 = countlen(l2);
        ListNode *head;
        if (len1 > len2) {
            head = dfs(l1, l2, len1-len2);
        } else {
            head = dfs(l2, l1, len2-len1);
        }
        if (head->val > 9) {
            auto nh = new ListNode(1, head);
            head->val %= 10;
            return nh;
        }
        return head;
    }
    ListNode *dfs(ListNode *l1, ListNode *l2, int diff) {
        if (!l1) {
            return nullptr;
        }
        if (diff) {
            l1->next = dfs(l1->next, l2, diff-1);
        } else {
            l1->val += l2->val;
            l1->next = dfs(l1->next, l2->next, 0);
        }
        if (l1->next && l1->next->val > 9) {
            l1->next->val %= 10;
            ++l1->val;
        }
        return l1;
    }
    int countlen(ListNode *now) {
        int len = 0;
        while (now) {
            now = now->next;
            ++len;
        }
        return len;
    }
};

//--- method 2: stack 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode *> s1, s2;
        while (l1) {
            s1.push_back(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.push_back(l2);
            l2 = l2->next;
        }
        return s1.size() > s2.size() ? iter(s1,s2) : iter(s2,s1);
    }
    ListNode *iter(vector<ListNode *> &s1, vector<ListNode *> &s2) {
        ListNode *last;
        while (s1.size() || s2.size()) {
            last = s1.back();
            if (s2.size()) {
                last->val += s2.back()->val;
                s2.pop_back();
            }
            if (last->next && last->next->val > 9) {
                last->next->val -= 10;
                ++last->val;
            }
            s1.pop_back();
        }
        if (last->val > 9) {
            last->val -= 10;
            return new ListNode(1, last);
        }
        return last;
    }
};


