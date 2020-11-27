//--- Q: 146. LRU Cache

//--- method 1: c++ STL list
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        pair<int,int> get_pair = *(it->second);
        ls.erase(it->second);
        ls.insert(ls.begin(), get_pair);
        map[key] = ls.begin();
        return ls.front().second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end())
            ls.erase(it->second);
        ls.push_front(make_pair(key, value));
        map[key] = ls.begin();
        if (map.size() > cap)
        {
            map.erase(ls.back().first);
            ls.pop_back();
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int,int>> ls;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */