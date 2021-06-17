//--- Q: 706. Design HashMap

//--- method 1: double array
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashv = key%1000, posv = key/1000;
        if (!map[hashv].size())
            map[hashv].resize(1000 + ((!posv) ? 1 : 0), -1);
        map[hashv][posv] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashv = key%1000, posv = key/1000;
        if (map[hashv].size())
            return map[hashv][posv];
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashv = key%1000, posv = key/1000;
        if (map[hashv].size())
            map[hashv][posv] = -1;
    }
    vector<vector<int>> map;
};

//--- method 2: array of list
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int loc = h(key)%1000;
        auto &ll = map[loc];
        for (auto &p: ll) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        ll.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int loc = h(key)%1000;
        auto &ll = map[loc];
        for (auto &p: ll) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int loc = h(key)%1000;
        auto &ll = map[loc];
        for (auto p = ll.begin(); p != ll.end(); ++p) {
            if (p->first == key) {
                ll.erase(p);
                return;
            }
        }
    }
    hash<int> h;
    vector<list<pair<int, int>>> map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */