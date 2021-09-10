//--- Q: 0706. Design HashMap

//--- method 1: array of list
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = h(key)%1000;
        for (auto it = data[pos].begin(); it != data[pos].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        data[pos].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = h(key)%1000;
        for (auto it = data[pos].begin(); it != data[pos].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = h(key)%1000;
        for (auto it = data[pos].begin(); it != data[pos].end(); ++it) {
            if (it->first == key) {
                data[pos].erase(it);
                return;
            }
        }
    }
    vector<list<pair<int,int>>> data;
    hash<int> h;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */