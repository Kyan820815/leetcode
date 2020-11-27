//--- Q: 380. Insert Delete GetRandom O(1)

//--- method 1: map and vector
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        now = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (!set.count(val))
        {
            set[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (set.count(val))
        {
            int idx = set[val];
            swap(nums[idx], nums.back());
            set[nums[idx]] = idx;
            set.erase(val);
            nums.pop_back();
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums.size() == 0 ? 0 : nums[rand()%nums.size()];
    }
private:
    unordered_map<int,int> set;
    vector<int> nums;
    int now;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */