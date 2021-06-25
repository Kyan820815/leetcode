//--- Q: 981. Time Based Key-Value Store

//--- method 1: map of unordered_map
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto pos = map[key].upper_bound(timestamp);
        if (pos == map[key].begin()) {
            return "";
        } else {
            return (--pos)->second;
        }
    }
    unordered_map<string, map<int, string>> map;
};

//--- method 2: vector pair of unordered_map
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto pos = upper_bound(map[key].begin(), map[key].end(), timestamp, [](int val, pair<int, string> &a) {
            return val < a.first;
        });
        if (pos == map[key].begin()) {
            return "";
        } else {
            return (--pos)->second;
        }
    }
    unordered_map<string, vector<pair<int, string>>> map;
};

//--- method 3: vector pair of unordered_map with binary search
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &vec = map[key];
        int left = 0, right = vec.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (vec[mid].first < timestamp) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (vec[left].first > timestamp) {
            return !left ? "" : vec[left-1].second;
        } else {
            return vec[left].second;
        }
    }
    unordered_map<string, vector<pair<int, string>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
