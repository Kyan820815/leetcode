//--- Q: 0023. Merge k Sorted Lists
//--- last written: 2023/07/01

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: recursive merge
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) {
            return NULL;
        }
        return divide(0, lists.size()-1, lists);
    }
    ListNode *divide(int start, int end, vector<ListNode*>& lists) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, lists);
            auto right = divide(mid+1, end, lists);
            return conquer(left, right);
        }
        return lists[start];
    }
    ListNode *conquer(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else {
            if (l1->val < l2->val) {
                l1->next = conquer(l1->next, l2);
                return l1;
            } else {
                l2->next = conquer(l1, l2->next);
                return l2;
            }
        }
    }
};

//--- method 1-2: iterative merge
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) {
            return NULL;
        }
        return divide(0, lists.size()-1, lists);
    }
    ListNode *divide(int start, int end, vector<ListNode*>& lists) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, lists);
            auto right = divide(mid+1, end, lists);
            return conquer(left, right);
        }
        return lists[start];
    }
    ListNode *conquer(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
