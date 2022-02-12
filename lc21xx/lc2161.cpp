//--- Q: 2161. Partition Array According to Given Pivot

//--- method 1: two array then combine
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), cnt = 0;
        vector<int> left, right;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                right.push_back(nums[i]);
            } else {
                ++cnt;
            }
        }
        for (int i = 0; i < cnt; ++i) {
            left.push_back(pivot);
        }
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

//--- method 2: one array and three pointers
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), low = 0, same = 0;
        vector<int> res(n, 0);
        for (auto &num: nums) {
            if (num < pivot) {
                ++low;
            } else if (num == pivot) {
                ++same;
            }
        }
        int high = low+same;
        same = low;
        low = 0;
        for (auto &num: nums) {
            if (num < pivot) {
                res[low++] = num;
            } else if (num == pivot) {
                res[same++] = num;
            } else {
                res[high++] = num;
            }
        }
        return res;
    }
};