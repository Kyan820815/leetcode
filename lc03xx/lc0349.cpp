//--- Q: 0349. Intersection of Two Arrays

//--- method 1: two pointer
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                res.push_back(nums1[i]);
                for (++i; i < nums1.size() && nums1[i] == nums1[i-1]; ++i);
                for (++j; j < nums2.size() && nums2[j] == nums2[j-1]; ++j);
            }
        }
        return res;
    }
};

//--- method 2: unordered_set solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set;
        for (auto &num: nums1) {
            set.insert(num);
        }
        for (auto &num: nums2) {
            if (set.find(num) != set.end()) {
                res.push_back(num);
                set.erase(num);
            }
        }
        return res;
    }
};