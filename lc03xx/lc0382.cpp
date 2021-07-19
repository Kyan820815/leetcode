//--- Q: 0382. Linked List Random Node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: resivoir sampling
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        hd = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        auto now = hd;
        int res;
        for (int cnt = 0; now; now=now->next, ++cnt) {
            if (random()%(cnt+1) == cnt) {
                res = now->val;
            }
        }
        return res;
    }
    ListNode *hd;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */