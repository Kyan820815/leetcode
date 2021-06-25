//--- Q: 359. Logger Rate Limiter

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
        if (map.find(message) == map.end()) {
            map[message] = timestamp;
            return true;
        } else if (timestamp - map[message] < 10) {
            return false;
        } else {
            map[message] = timestamp;
            return true;
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
        {
            unique_lock<mutex> lk(mtx);
            if (map.find(message) == map.end()) {
                map[message] = timestamp;
                return true;
            } else if (timestamp - map[message] < 10) {
                return false;
            } else {
                map[message] = timestamp;
                return true;
            }
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
        while (que.size() && que.front().second+10 <= timestamp) {
            set.erase(que.front().first);
            que.pop();
        }
        if (set.find(message) != set.end()) {
            return false;
        } else {
            que.push({message, timestamp});
            set.insert(message);
            return true;
        }
    }
    unordered_set<string> set;
    queue<pair<string, int>> que;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */