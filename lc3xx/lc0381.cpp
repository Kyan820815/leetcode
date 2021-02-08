//--- Q: 381. Insert Delete GetRandom O(1) - Duplicates allowed

//--- method 1: map operation
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool have = map.find(val) == map.end();
        arr.push_back({map[val].size(), val});
        map[val].push_back(arr.size()-1);
        return have;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool have = map.find(val) != map.end();
        if (have) {
            auto last = arr.back();
            int pos = map[val].back();
            map[last.second][last.first] = pos;
            swap(arr[map[val].back()], arr.back());
            arr.pop_back();
            map[val].pop_back();
            if (!map[val].size()) {
                map.erase(val);
            }
        }

        return have;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[random()%arr.size()].second;
    }
    vector<pair<int, int>> arr;
    unordered_map<int, vector<int>> map;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */