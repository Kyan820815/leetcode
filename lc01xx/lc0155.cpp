//--- Q: 0155. Min Stack

//--- method 1: one stack O(1) operation
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        sk.push_back(minv);
    }
    
    void push(int val) {
        if (val <= minv) {
            sk.push_back(minv);
            minv = val;
        }
        sk.push_back(val);
    }
    
    void pop() {
        if (minv == sk.back()) {
            sk.pop_back();
            minv = sk.back();
        }
        sk.pop_back();
    }
    
    int top() {
        return sk.back();
    }
    
    int getMin() {
        return minv;
    }
    vector<int> sk;
    int minv = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */