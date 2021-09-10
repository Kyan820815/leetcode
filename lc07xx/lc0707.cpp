//--- Q: 0707. Design Linked List

//--- method 1: dummy and linear finding index node
class LNode {
public:
    LNode(int v) {
        val = v;
        next = nullptr;
    }
    int val;
    LNode *next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new LNode(-1);
        sz = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= sz) {
            return -1;
        }
        auto now = dummy->next;
        while (index--) {
            now = now->next;
        }
        return now->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(sz, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > sz) {
            return;
        }
        ++sz;
        auto now = dummy->next, pre = dummy;
        while (index--)  {
            pre = now;
            now = now->next;
        }
        pre->next = new LNode(val);
        pre->next->next = now;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= sz) {
            return;
        }
        --sz;
        auto now = dummy;
        while (index--) {
            now = now->next;
        }
        now->next = now->next->next;
    }
    int sz;
    LNode *dummy;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */