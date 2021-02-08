//--- Q: 933. Number of Recent Calls

//--- method 1: queue
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (que.size() && que.front() < t-3000) {
            que.pop();
        }
        que.push(t);
        return que.size();
    }
    queue<int> que;
};

//--- method 2: arr
class RecentCounter {
public:
    RecentCounter() {
        idx.resize(3001, -3000);
    }
    
    int ping(int t) {
        int cnt = 0;
        idx[t%3001] = t;
        for (int i = 0; i < 3001; ++i)  {
            if (t-idx[i] <= 3000) {
                ++cnt;
            }
        }
        return cnt;
    }
    vector<int> idx;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */