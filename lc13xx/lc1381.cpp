//--- Q: 1381. Design a Stack With Increment Operation

//--- method 1: lazy increment
class CustomStack {
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (vec.size() < size) {
            vec.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        int val = -1;
        if (vec.size()) {
            int idx = vec.size()-1;
            if (idx) {
                inc[idx-1] += inc[idx];
            }
            val = vec.back() += inc[idx];
            inc.pop_back();
            vec.pop_back();
        }
        return val;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)vec.size());
        if (k) {
            inc[k-1] += val;
        }
    }
    vector<int> vec, inc;
    int size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */