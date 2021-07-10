//--- Q: 0225. Implement Stack using Queues

//--- method 1: refactor queue while pop
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        last_top = INT_MAX;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        last_top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        auto val = last_top;
        while (que.size() > 1) {
            last_top = que.front();
            tmp.push(que.front());
            que.pop();
        }
        que = tmp;
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return last_top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !que.size();
    }
    
    int last_top;
    
    queue<int> que;
};

//--- method 2: reverse queue while push x
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size()-1; ++i) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto val = que.front();
        que.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !que.size();
    }
    
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */