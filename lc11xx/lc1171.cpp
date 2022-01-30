//--- Q: 1171. Remove Zero Sum Consecutive Nodes from Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--- method 1: prefix sum
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        unordered_map<int, ListNode *> map;
        map[0] = dummy;
        int sum = 0;
        auto now = head;
        while (now) {
            sum += now->val;
            if (map.find(sum) != map.end()) {
                auto cur = map[sum]->next;
                int cursum = sum;
                while (cur != now) {
                    cursum += cur->val;
                    map.erase(cursum);
                    cur = cur->next;
                }
                map[sum]->next = now->next;
            } else {
                map[sum] = now;
            }
            now = now->next;
        }
        return dummy->next;
    }
};