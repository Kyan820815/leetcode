//--- Q: 25. Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head, *dummy = new ListNode(-1);
        ListNode *nowH = head, *pre = dummy;
        dummy->next = head;
        int cnt = 0;
        while (cur)
        {
            cnt++;
            cur = cur->next;
            if (cnt == k)
            {
                cnt = 0;
                ListNode *revH = cur, *t = nowH;
                while (nowH != cur)
                {
                    ListNode *tmp = nowH->next;
                    nowH->next = revH;
                    revH = nowH;
                    nowH = tmp;
                }
                pre->next = revH;
                pre = t;
            }
        }
        return dummy->next;
    }
};