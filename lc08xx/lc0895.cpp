//--- Q: 0895. Maximum Frequency Stack

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

//--- method 1: stack impl
class FreqStack {
public:
    FreqStack() {
        maxcnt = 0;
    }
    
    void push(int val) {
        int times = ++cnt[val];
        freq[times].push_back(val);
        maxcnt = max(maxcnt, times);
    }
    
    int pop() {
        int val = freq[maxcnt].back();
        freq[maxcnt].pop_back();
        if (!freq[maxcnt].size()) {
            --maxcnt;
        }
        --cnt[val];
        return val;
    }
    unordered_map<int, vector<int>> freq;
    unordered_map<int, int> cnt;
    int maxcnt;
};

//--- method 2: list impl
class FreqStack {
public:
    FreqStack() {
        maxcnt = 0;
    }
    
    void push(int val) {
        int times = ++cnt[val];
        ll.push_back(val);
        freq[times].push_back(prev(ll.end()));
        maxcnt = max(maxcnt, times);
    }
    
    int pop() {
        auto pos = freq[maxcnt].back();
        freq[maxcnt].pop_back();
        if (!freq[maxcnt].size()) {
            --maxcnt;
        }
        int val = *pos;
        --cnt[val];
        ll.erase(pos);
        return val;
    }
    list<int> ll;
    unordered_map<int, vector<list<int>::iterator>> freq;
    unordered_map<int, int> cnt;
    int maxcnt;
};