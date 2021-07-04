//--- Q: 0128. Longest Consecutive Sequence

//--- method 1: unordered_map
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for (auto &num: nums) {
            if (map.find(num) != map.end()) {
                continue;
            }
            int left_len = map.find(num-1) == map.end() ? 0 : map[num-1];
            int right_len = map.find(num+1) == map.end() ? 0 : map[num+1];
            int total_len = left_len+right_len+1;
            res = max(res, total_len);
            map[num-left_len] = map[num+right_len] = map[num] = total_len;
        }
        return res;
    }
};

//--- method 2: unordered_set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto &num: nums) {
            set.insert(num);
        }
        int res = 0;
        for (auto &num: nums) {
            int len = 1, val = num;
            while (set.find(val+1) != set.end()) {
                set.erase(val+1);
                ++val, ++len;
            }
            val = num;
            while (set.find(val-1) != set.end()) {
                set.erase(val-1);
                --val, ++len;
            }
            res = max(res, len);
        }
        return res;
    }
};