//--- Q: 460. LFU Cache

//--- method 1:
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        min_cnt = 1;
        sz = 0;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        int cur_cnt = key_cnt[key]++;
        auto pk = *map[key];
        ll[cur_cnt].erase(map[key]);
        ll[key_cnt[key]].push_front(pk);
        map[key] = ll[key_cnt[key]].begin();
        if (!ll[min_cnt].size()) {
            ++min_cnt;
        }
        return pk.second;
    }
    
    void put(int key, int value) {
        if (!cap) {
            return;
        }
        pair<int,int> pk;
        if (get(key) != -1) {
            map[key]->second = value;
            return;
        }
        pk = {key, value};
        if (sz == cap) {
            auto pk = ll[min_cnt].back();
            map.erase(pk.first);
            --key_cnt[pk.first];
            ll[min_cnt].pop_back();
            if (!ll[min_cnt].size()) {
                ++min_cnt;
            }
            --sz;
        }
        ll[1].push_front(pk);
        map[key] = ll[1].begin();
        key_cnt[key] = 1;
        min_cnt = 1;
        ++sz;
    }
    unordered_map<int,list<pair<int,int>>::iterator> map;
    unordered_map<int, list<pair<int,int>>> ll;
    unordered_map<int,int> key_cnt;
    int min_cnt, cap, sz;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */