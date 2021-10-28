//--- Q: 0716. Max Stack

//--- method 1: map operation
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        sk.push_back(x);
        map[x].push_back(prev(sk.end()));
    }
    
    int pop() {
        auto val = sk.back();
        sk.pop_back();
        map[val].pop_back();
        if (!map[val].size()) {
            map.erase(val);
        }
        return val;
    }
    
    int top() {
        return sk.back();
    }
    
    int peekMax() {
        return map.rbegin()->first;
    }
    
    int popMax() {
        auto pos = map.rbegin()->second.back();
        auto val = *pos;
        map.rbegin()->second.pop_back();
        sk.erase(pos);
        if (!map.rbegin()->second.size()) {
            map.erase(val);
        }
        return val;
    }
    
    list<int> sk;
    map<int, vector<list<int>::iterator>> map;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */