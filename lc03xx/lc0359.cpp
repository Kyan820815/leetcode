//--- Q: 0359. Logger Rate Limiter

//--- method 1: map
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (map.find(message) == map.end() || map[message]+10 <= timestamp) {
            map[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
    unordered_map<string, int> map;
};

//--- method 1, follow up: thread safe map
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        unique_lock<mutex> ulock(mtx);
        if (map.find(message) == map.end() || map[message]+10 <= timestamp) {
            map[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
    unordered_map<string, int> map;
    mutex mtx;
};

//--- method 2: queue & set
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (que.size() && que.front().first+10 <= timestamp) {
            set.erase(que.front().second);
            que.pop();
        }
        if (set.find(message) != set.end()) {
            return false;
        }
        que.push({timestamp, message});
        set.insert(message);
        return true;
    }
    
    queue<pair<int, string>> que;
    unordered_set<string> set;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */