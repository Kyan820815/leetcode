//--- Q: 362. Design Hit Counter

//--- method 1: fancy array method
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        time.resize(300, 0);
        hitcnt.resize(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int slot = timestamp % 300;
        if (time[slot] != timestamp) {
            hitcnt[slot] = 1;
            time[slot] = timestamp;
        } else
            ++hitcnt[slot];
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int cnt = 0;
        for (int i = 0; i < 300; ++i) {
            if (time[i] > timestamp-300)
                cnt += hitcnt[i];
        }
        return cnt;
    }
    vector<int> time, hitcnt;
};

//--- method 2: queue operation
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        cnt = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while (que.size() && que.front().first <= timestamp-300) {
            cnt -= que.front().second;
            que.pop();
        }
        if (que.size() && que.back().first == timestamp)
            ++que.back().second;
        else
            que.push({timestamp, 1});
        ++cnt;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (que.size() && que.front().first <= timestamp-300) {
            cnt -= que.front().second;
            que.pop();
        }
        return cnt;
    }
    int cnt;
    queue<pair<int, int>> que;
};

//--- method 3: sliding window (no good)
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        left = 1, right = 300, maxv = 0;
        arr.resize(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (timestamp <= right) {
            ++maxv;
            ++arr[timestamp-left];
        } else {
            int newleft = timestamp-299;
            if (newleft > right) {
                left = newleft, right = timestamp;
                fill(arr.begin(), arr.end(), 0);
                ++arr[timestamp-left];
                maxv = 1;
            } else {
                vector<int> newarr(300, 0);
                ++maxv;
                for (int i = left; i < newleft; ++i)
                    maxv -= arr[i-left];
                for (int i = newleft; i <= right; ++i)
                    newarr[i-newleft] = arr[i-left];
                right = timestamp;
                left = newleft;
                ++newarr[right-left];
                arr = newarr;
                newarr = vector<int>();
            }
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if (timestamp > right) {
            int newleft = timestamp-299;
            if (newleft > right) {
                left = newleft, right = timestamp;
                fill(arr.begin(), arr.end(), 0);
                maxv = 0;
            } else {
                vector<int> newarr(300, 0);
                for (int i = left; i < newleft; ++i)
                    maxv -= arr[i-left];
                for (int i = newleft; i <= right; ++i)
                    newarr[i-newleft] = arr[i-left];
                right = timestamp;
                left = newleft;
                arr = newarr;
                newarr = vector<int>();
            }
        }
        return maxv;            
    }
    int left, right, maxv;
    vector<int> arr;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */