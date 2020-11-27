//--- Q: 382. Linked List Random Node

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
    	cpy = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
    	ListNode *now = cpy->next;
    	int len = 2, res = cpy->val;
        while(now != NULL)
        {
        	if (rand()%len == 0)
        		res = now->val;
        	now = now->next;
        	len++;
        	
        }
    	return res;
    }
private:
	ListNode *cpy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */