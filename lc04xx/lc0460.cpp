//--- Q: 0460. LFU Cache

//--- method 1: vector of list with key count data structure
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity, sz = 0, min_cnt = 0; 
    }
    
    int get(int key) {
        if (loc_map.find(key) == loc_map.end()) {
            return -1;
        }
        auto pkg = *loc_map[key];
        auto key_cnt = key_cnt_map[key]++;
        cache[key_cnt].erase(loc_map[key]);
        key_cnt = key_cnt_map[key];
        cache[key_cnt].push_front(pkg);
        loc_map[key] = cache[key_cnt].begin();
        if (!cache[min_cnt].size()) {
            ++min_cnt;
        }
        return pkg.second;
    }
    
    void put(int key, int value) {
        if (!cap) {
            return;
        }
        if (get(key) != -1) {
            loc_map[key]->second = value;
            return;
        }
        if (sz == cap) {
            auto key = cache[min_cnt].back().first;
            cache[min_cnt].pop_back();
            key_cnt_map[key] = 0;
            loc_map.erase(key);
            --sz;
        }
        pair<int,int> pkg = {key,value};
        min_cnt = 1, ++sz;
        cache[min_cnt].push_front(pkg);
        key_cnt_map[key] = 1;
        loc_map[key] = cache[min_cnt].begin();
    }
    unordered_map<int, list<pair<int,int>>::iterator> loc_map;
    unordered_map<int, list<pair<int,int>>> cache;
    unordered_map<int, int> key_cnt_map;
    int min_cnt, cap, sz;
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */