//--- Q: 0981. Time Based Key-Value Store

//--- method 1: vector pair of unordered_map with binary search
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        int left = 0, right = map[key].size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (map[key][mid].first < timestamp) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        if (map[key][left].first > timestamp) {
            return !left ? "" : map[key][left-1].second;
        } else {
            return map[key][left].second;
        }
    }
    unordered_map<string, vector<pair<int,string>>> map;
};

//--- method 2: map of unordered_map
class TimeMap {
public:
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
            return prev(pos)->second;
        }
    }
    unordered_map<string,map<int,string>> map;
};