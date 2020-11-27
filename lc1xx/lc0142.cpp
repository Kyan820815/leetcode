//--- Q: 142. Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: slow & fast pointer, better
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast, *entry;
        fast = slow = entry = head;
        
        if (head == NULL || head->next == NULL)
            return NULL;

        while(1)
        {
            if (fast != NULL && fast->next!= NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow)
                    break; 
            }
            else
                return NULL;
        }
        
        while(entry != slow)
        {
            entry = entry->next;
            slow = slow->next;
        }
        return entry;
    }
};

//--- method 2: hash map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,ListNode*> nodeMap;
        ListNode *cur;
        cur = head;
        while(cur != NULL)
        {
            if (nodeMap.count(cur))
                break;
            else
                nodeMap[cur] = cur->next;
            cur = cur->next;
        }
        return cur;
    }
};

//--- method 3: not good
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *cur;

        cur = head;
        while(cur != NULL && cur->val != -1000)
        {
        	cur->val = -1000;
        	cur = cur->next;
        }
        return cur;
    }
};