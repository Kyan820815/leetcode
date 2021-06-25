//--- Q: 128. Longest Consecutive Sequence

//--- method 1: unordered_set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> map(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!map.count(nums[i])) continue;
            map.erase(nums[i]);
            int left = nums[i]-1;
            while (map.count(left))
            {
                map.erase(left);
                --left;
            }
            int right = nums[i]+1;
            while (map.count(right))
            {
                map.erase(right);
                ++right;
            }
            res = max(res, right-left-1);
        }
        return res;
    }
};

//--- method 2: unordered_map
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(nums[i]) != map.end())
                continue;
            int left = !map.count(nums[i]-1) ? 0 : map[nums[i]-1];
            int right = !map.count(nums[i]+1) ? 0 : map[nums[i]+1];
            int sum = left+right+1;
            map[nums[i]] = sum;
            map[nums[i]-left] = sum;
            map[nums[i]+right] = sum;
            res = max(res, sum);
        }
        return res;
    }
};