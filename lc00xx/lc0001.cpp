//--- Q: 0001. Two Sum
//--- last written: 2023/03/11

//--- method 1-1: sort then find index from left and right, better
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx;
        for (int i = 0; i < nums.size(); ++i) {
            idx.push_back(i);
        }
        divide(0, nums.size()-1, nums, idx);
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[idx[left]] + nums[idx[right]] < target) {
                ++left;
            } else if (nums[idx[left]] + nums[idx[right]] > target) {
                --right;
            } else {
                return {idx[left],idx[right]};
            }
        }
        return {};
    }
    void divide(int start, int end, vector<int> &nums, vector<int> &idx) {
        if (start < end) {
            int mid = start + (end-start)/2;
            divide(start, mid, nums, idx);
            divide(mid+1, end, nums, idx);
            conquer(start, mid, end, nums, idx);
        }
    }
    void conquer(int start, int mid, int end, vector<int> &nums, vector<int> &idx) {
        vector<int> cpy;
        int i = start, j = mid+1;
        while (i <= mid && j <= end) {
            if (nums[idx[i]] < nums[idx[j]]) {
                cpy.push_back(idx[i++]);
            } else {
                cpy.push_back(idx[j++]);
            }
        }
        while (i <= mid) {
            cpy.push_back(idx[i++]);
        }
        while (j <= end) {
            cpy.push_back(idx[j++]);
        }
        for (int i = start; i <= end; ++i) {
            idx[i] = cpy[i-start];
        }
    }
};

//--- method 1-2: built-in sort
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx;
        for (int i = 0; i < nums.size(); ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[idx[left]] + nums[idx[right]] < target) {
                ++left;
            } else if (nums[idx[left]] + nums[idx[right]] > target) {
                --right;
            } else {
                return {idx[left], idx[right]};
            }
        }
        return {-1,-1};
    }
};

//--- method 2: hash map one way (unordered map)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> sumMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (sumMap.find(nums[i]) != sumMap.end()) {
                res.push_back(sumMap[nums[i]]);
                res.push_back(i);
            } else {
                sumMap[target-nums[i]] = i;
            }
        }
        return res;
    }
};
