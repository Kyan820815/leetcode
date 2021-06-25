//--- Q: 146. LRU Cache

//--- method 1: c++ STL list
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;        
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        auto pk = *map[key];
        ll.erase(map[key]);
        ll.push_front(pk);
        map[key] = ll.begin();
        return ll.begin()->second;
    }
    
    void put(int key, int value) {
        pair<int,int> pk;
        if (get(key) != -1) {
            map[key]->second = value;
            return;
        }
        pk = {key, value};
        ll.push_front(pk);
        map[key] = ll.begin();
        if (ll.size() > cap) {
            map.erase(ll.back().first);
            ll.pop_back();
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */