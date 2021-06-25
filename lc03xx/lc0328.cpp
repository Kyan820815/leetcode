//--- Q: 328. Odd Even Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: one pass O(n), better
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *now = head;
        ListNode *odd, *even, *dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1);
        odd = dummy1;
        even = dummy2;
        while(now && now->next)
        {
        	odd->next = now;
        	odd = odd->next;
        	even->next = now->next;
        	even = even->next;
        	now = now->next->next;
        }
        if (now)
        {
        	odd->next = now;
        	odd = odd->next;
        }
        odd->next = dummy2->next;
        even->next = NULL;
        return dummy1->next;
    }
};

//--- method 2: one pass O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd, *even, *even_head;
        if (!head || !head->next) return head;
        odd = head;
        even = even_head = head->next;
        while(odd && even)
        {
        	odd->next = even->next;
        	if (odd->next)
        		odd = odd->next;
        	else break;
        	even->next = odd->next;
        	even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

//--- method 3: one pass O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *pre, *cur, *dummy = new ListNode(-1);
        dummy->next = head;
        pre = dummy, cur = head;
        while(cur && cur->next)
        {
        	pre->next = cur->next;
        	cur->next = cur->next->next;
        	pre = pre->next;
            if (!cur->next)
                break;
        	cur = cur->next;
        }
        if (pre != dummy)
        {
        	cur->next = dummy->next;
            pre->next = NULL;
        }
        return head;
    }
};