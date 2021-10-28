//--- Q: 1265. Print Immutable Linked List in Reverse

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */


//--- method 1: O(n) time O(n) space
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head) {
            return;
        }
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};

//--- method 2: O(n^2) time O(1) space
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        auto now = head;
        int len = 0;
        while (now) {
            ++len;
            now = now->getNext();
        }
        while (len) {
            auto tmp = head;
            int tmplen = len;
            while (--tmplen) {
                tmp = tmp->getNext();
            }
            tmp->printValue();
            --len;
        }
    }
};

//--- method 3: O(n) time O(sqrt(n)) space
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        int sz = 0;
        auto now = head;
        while (now) {
            now = now->getNext();
            ++sz;
        }
        int len = sqrt(sz);
        vector<ImmutableListNode *> sk;
        now = head;
        while (sk.size() < len) {
            sk.push_back(now);
            for (int i = 0; i < len; ++i) {
                now = now->getNext();
            }
        }
        ImmutableListNode *last = nullptr;
        while (sk.size()) {
            vector<ImmutableListNode *> tmpsk;
            auto now = sk.back(), next_last = now;
            sk.pop_back();
            while (now != last) {
                tmpsk.push_back(now);
                now = now->getNext();
            }
            while (tmpsk.size()) {
                tmpsk.back()->printValue();
                tmpsk.pop_back();
            }
            last = next_last;
        }
    }
};