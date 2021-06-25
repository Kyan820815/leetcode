//--- Q: 0015. 3Sum

//--- method 1: build-in sort
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-2; ++i) {
            if (i && nums[i] == nums[i-1] || nums[i] + nums[n-2] + nums[n-1] < 0) {
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] > 0) {
                break;
            }
            int left = i+1, right = n-1, target = -nums[i];
            while (left < right) {
                if (nums[left] + nums[right] < target) {
                    ++left;
                } else if (nums[left] + nums[right] > target) {
                    --right;
                } else {
                    res.push_back({-target, nums[left], nums[right]});
                    ++left, --right;
                    while (left < right && nums[left] == nums[left-1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};

//--- method 2: no sort O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> dup;
        unordered_map<int, int> seen;
        set<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (dup.find(nums[i]) == dup.end()) {
                dup.insert(nums[i]);
                for (int j = i+1; j < n; ++j) {
                    int comp = -nums[i]-nums[j];
                    if (seen.find(comp) != seen.end() && seen[comp] == i) {
                        vector<int> arr = {nums[i], nums[j], comp};
                        sort(arr.begin(), arr.end());
                        res.insert(arr);
                    }
                    seen[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};