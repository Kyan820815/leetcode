//--- Q: 0232. Implement Queue using Stacks

//--- method 1: two stack，one for buffer, reduce time consuming
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sk1.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto val = peek();
        sk2.pop_back();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (!sk2.size()) {
            inject();
        }
        return sk2.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !sk1.size() && !sk2.size();
    }
    
    void inject() {
        while (sk1.size()) {
            sk2.push_back(sk1.back());
            sk1.pop_back();
        }
    }
    
    vector<int> sk1, sk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */