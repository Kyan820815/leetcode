//--- Q: 143. Reorder List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: better solution
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next, *last = NULL;
        slow->next = NULL;
        while (cur)
        {
            ListNode *next_node = cur->next;
            cur->next = last;
            last = cur;
            cur = next_node;
        }
        cur = head;
        while (last)
        {
            ListNode *tmp = last;
            last = last->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
    }
};

//--- method 2: O(1) space
class Solution {
public:
    void reorderList(ListNode* head) {
        
    	ListNode *slow, *fast;
    	slow = fast = head;
    	while(fast && fast->next)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	ListNode *right, *right_head, tmp;
    	right = slow;
    	right_head = NULL;
    	while(right)
    	{
    		tmp = right;
    		right = right->next;
    		tmp->next = right_head;
    		right_head = tmp;
    	}
    	ListNode *left;
    	left = head;
    	//--- version 1
    	while(left != slow || left->next != slow)
    	{
    		tmp = left->next;
    		left->next = right_head;
    		right_head = right_head->next;
    		left->next->next = tmp;
    		left = tmp;
    	}
    	left->next = right_head;
    	
    	//--- version 2
    	while(left != slow)
    	{
    		tmp = left->next;
    		left->next = right_head;
    		right_head = right_head->next;
    		left->next->next = tmp;
            if (left->next == left->next->next)
            {
                left->next->next = NULL;
                break;
            }
    		left = tmp;
    	}
    }
};