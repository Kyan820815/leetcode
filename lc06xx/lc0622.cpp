//--- Q: 622. Design Circular Queue

//--- method 1: use lenth as tag
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        que.resize(size, 0);
        start = 0, end = -1;
        cnt = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (cnt == size)
            return false;
        ++end;
        if (end >= size)
            end %= size;
        que[end] = value;
        cnt++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!cnt)
            return false;
        ++start;
        if (start >= size)
            start %= size;
        cnt--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return !cnt ? -1 : que[start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return !cnt ? -1 : que[end];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cnt == size;
    }
    vector<int> que;
    int start, end;
    int cnt, size;
};

//--- method 2: use boolean as tag
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        que.resize(size, 0);
        start = 0, end = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
    	if (isFull())
    		return false;
    	if (start == end && empty)
    		empty = false;
        que[end] = value;
        end = (end+1+size) % size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
    	if (isEmpty())
    		return false;
        ++start;
        if (start >= size)
            start %= size;
    	if (start == end && !empty)
            empty = true;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : que[start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : que[(end-1+size) % size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return start == end && empty;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return start == end && !empty;
    }
    vector<int> que;
    int start, end, size;
    bool empty = true;
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
