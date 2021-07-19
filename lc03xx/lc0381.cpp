//--- Q: 0381. Insert Delete GetRandom O(1) - Duplicates allowed

//--- method 1: map operation
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool find = !map[val].size();
        map[val].push_back(arr.size());
        arr.push_back({val,map[val].size()-1});
        return find;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!map[val].size()) {
            return false;
        }
        auto last = arr.back();
        map[last.first][last.second] = map[val].back();
        swap(arr.back(), arr[map[val].back()]);
        map[val].pop_back();
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[random()%arr.size()].first;
    }
    vector<pair<int, int>> arr;
    map<int, vector<int>> map;
};



/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */