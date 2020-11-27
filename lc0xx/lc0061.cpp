//--- Q: 061. Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: linklist operation
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0, go;
        ListNode *cur, *prev, *rear;

        if (!head) return head;
        cur = head;
        while(cur)
        {
        	len++;
        	if (!cur->next) rear = cur;
        	cur = cur->next;
        }
        k = k%len;
        if (!k) return head;
        go = len-k;
        cur = head;

        for (int i = 0; i < go; ++i)
        {
        	prev = cur;
        	cur = cur->next;
        }
        prev->next = NULL;
        rear->next = head;
        return cur;
    }
};