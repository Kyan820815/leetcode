//--- Q: 0380. Insert Delete GetRandom O(1)

//--- method 1: map and vector
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        auto last = arr.back();
        map[arr.back()] = map[val];
        swap(arr.back(), arr[map[val]]);
        arr.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[random()%arr.size()];
    }
    unordered_map<int, int> map;
    vector<int> arr;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */