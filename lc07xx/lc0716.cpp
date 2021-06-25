//--- Q: 716. Max Stack

//--- method 1: map operation
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        lst.push_back(x);
        mp[x].push_back(prev(lst.end()));
    }
    
    int pop() {
        int v = lst.back();
        mp[v].pop_back();
        if (!mp[v].size()) {
            mp.erase(v);
        }
        lst.pop_back();
        return v;
    }
    
    int top() {
        return lst.back();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int v = mp.rbegin()->first;
        lst.erase(mp[v].back());
        mp[v].pop_back();
        if (!mp[v].size()) {
            mp.erase(v);
        }
        return v;
    }
    
    map<int, vector<list<int>::iterator>> mp;
    list<int> lst;
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