//--- Q: 0933. Number of Recent Calls

//--- method 1: queue
class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        que.push(t);
        while (que.size() && t-3000 > que.front()) {
            que.pop();
        }
        return que.size();
    }
    queue<int> que;
};

//--- method 2: arr
class RecentCounter {
public:
    RecentCounter() {
        idx.resize(3001, 0);
    }
    
    int ping(int t) {
        idx[t%3001] = t;
        int res = 0;
        for (int i = 0; i < 3001; ++i) {
            res += t-3000 <= idx[i] && idx[i] > 0;
        }
        return res;
    }
    vector<int> idx;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */