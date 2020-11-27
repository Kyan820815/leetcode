//--- Q: 641. Design Circular Deque

//--- method 1: use lenth as tag
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        start = 0, end = 0, len = 0, size = k;
        deque.resize(size);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        if (len != 0)
            start = (start-1+size) % size;
        deque[start] = value;
        ++len;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        if (len != 0)
            end = (end+1) % size;
        deque[end] = value;
        ++len;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        if (len != 1)
            start = (start+1) % size;
        --len;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        if (len != 1)
            end = (end-1+size) % size;
        --len;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : deque[start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : deque[end];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return !len;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len == size;
    }
    vector<int> deque;
    int start, end, size, len;
};

//--- method 2: start & end
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        que.resize(k);
        empty = true;
        start = end = 0;
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        --start;
        start = (start + size) % size;
        que[start] = value;
        if (start == end) {
            empty = false;
        }
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        que[end] = value;
        end = (end+1) % size;
        if (start == end) {
            empty = false;
        }
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        start = (start + 1) % size;
        if (start == end) {
            empty = true;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        end = (end-1+size) % size;
        if (start == end) {
            empty = true;
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return que[start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return que[(end-1+size) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return start == end && empty;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return start == end && !empty;
    }
    vector<int> que;
    int start, end, size;
    bool empty;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */