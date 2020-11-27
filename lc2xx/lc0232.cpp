//--- Q: 232. Implement Queue using Stacks

//--- method 1: reverse stack each time while push x
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (sk.size())
        {
            tmp.push(sk.top());
            sk.pop();
        }
        sk.push(x);
        while (tmp.size())
        {
            sk.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = sk.top();
        sk.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return sk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !sk.size() ? true : false;
    }
private:
    stack<int> sk;
};

//--- method 2: two stack，one for buffer, reduce time consuming
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sk_tmp.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shift_stack();
        int res = sk_now.top();
        sk_now.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        shift_stack();
        return sk_now.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !sk_now.size() && !sk_tmp.size() ? true : false;
    }
    void shift_stack()
    {
        if (sk_now.size())
            return;
        while (sk_tmp.size())
        {
            sk_now.push(sk_tmp.top());
            sk_tmp.pop();
        }
    }
private:
    stack<int> sk_now;
    stack<int> sk_tmp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */