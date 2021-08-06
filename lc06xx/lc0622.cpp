//--- Q: 0622. Design Circular Queue

//--- method 1: use lenth as tag
cclass MyCircularQueue {
public:
    MyCircularQueue(int k) {
        len = k;
        arr.resize(k, 0);
        start = end = 0;
        empty = 1;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        arr[end] = value;
        end = end == len-1 ? 0 : end+1;
        empty = !(start == end);
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        start = start == len-1 ? 0 : start+1;
        empty = (start == end);
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[start];
    }
    
    int Rear() {
        auto ridx = !end ? len-1 : end-1;
        return isEmpty() ? -1 : arr[ridx];
    }
    
    bool isEmpty() {
        return start == end && empty;
    }
    
    bool isFull() {
        return start == end && !empty;
    }
    int start, end, len, empty;
    vector<int> arr;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
