//--- Q: 0641. Design Circular Deque

//--- method 1: use start and end
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        start = end = 0, len = k, empty = 1;
        arr.resize(k, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        start = !start ? len-1 : start-1;
        arr[start] = value;
        empty = !(start == end);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        arr[end] = value;
        end = end == len-1 ? 0 : end+1;
        empty = !(start == end);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        start = start == len-1 ? 0 : start+1;
        empty = (start == end);
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        end = !end ? len-1 : end-1;
        empty = (start == end);
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : arr[start];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        auto ridx = !end ? len-1 : end-1;
        return isEmpty() ? -1 : arr[ridx];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return start == end && empty;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return start == end && !empty;
    }
    int start, end, len, empty;
    vector<int> arr;
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