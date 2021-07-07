//--- Q: 0146. LRU Cache

//--- method 1: c++ STL list
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;        
    }

    int get(int key) {
        if (map.find(key) == map.end())  {
            return -1;
        }
        auto pkg = *map[key];
        ll.erase(map[key]);
        ll.insert(ll.begin(), pkg);
        map[key] = ll.begin();
        return pkg.second;
    }
    
    void put(int key, int value) {
        pair<int, int> pkg;
        if (get(key) != -1) {
            map[key]->second = value;
        } else {
            pkg = {key, value};
            ll.insert(ll.begin(), pkg);
            map[key] = ll.begin();
            if (ll.size() > cap) {
                map.erase(ll.back().first);
                ll.pop_back();
            }
        }
    }
    
    unordered_map<int, list<pair<int,int>>::iterator> map;
    list<pair<int,int>> ll;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */