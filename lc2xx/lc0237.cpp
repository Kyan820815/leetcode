//--- Q: 237. Delete Node in a Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: link list operation
class Solution {
public:
    void deleteNode(ListNode* node) {
    	ListNode *cur;
    	cur = node;
    	while (cur->next)
    	{
    		cur->val = cur->next->val;
            if (!cur->next->next)
            {
                cur->next = NULL;
                break;
            }
    		cur = cur->next;
    	}
    }
};