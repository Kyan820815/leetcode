//--- Q: 1429. First Unique Number

//--- method 1: list with map, O(1) for both operations
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        int val = unique.size() ? unique.front() : -1;
        return unique.size() ? unique.front() : -1;
    }
    
    void add(int value) {
        if (cnt.find(value) == cnt.end()) {
            unique.push_back(value);
            cnt[value] = prev(unique.end());
        } else if (cnt[value] != unique.end()){
            unique.erase(cnt[value]);
            cnt[value] = unique.end();
        }
    }
    unordered_map<int, list<int>::iterator> cnt;
    list<int> unique;
};

//--- method 2: queue，O(n) time for find first unique
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            if (cnt[nums[i]] == 1) {
                que.push(nums[i]);
            }
        }
    }
    
    int showFirstUnique() {
        while (que.size() && cnt[que.front()] > 1) {
            que.pop();
        }
        return que.size() ? que.front() : -1;
    }
    
    void add(int value) {
        if (++cnt[value] == 1) {
            que.push(value);
        }
    }
    unordered_map<int, int> cnt;
    queue<int> que;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */