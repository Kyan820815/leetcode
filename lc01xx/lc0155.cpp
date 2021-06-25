//--- Q: 155. Min Stack

//--- method 1: one stack O(1) operation
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minv = INT_MAX;
    }
    
    void push(int x) {
        if (minv >= x) {
            sk.push_back(minv);
            minv = x;
        }
        sk.push_back(x);
    }
    
    void pop() {
        int tmp = sk.back();
        sk.pop_back();
        if (minv == tmp) {
            minv = sk.back();
            sk.pop_back();
        }
    }
    
    int top() {
        return sk.back();
    }
    
    int getMin() {
        return minv;
    }
    vector<int> sk;
    int minv;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */