//---  Q: 0350. Intersection of Two Arrays II

//--- method 1: two pointer
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                res.push_back(nums1[i]);
                ++i, ++j;
            }
        }
        return res;
    }
};

//--- method 2: map solution
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (auto &num: nums1) {
            ++map[num];
        }
        for (auto &num: nums2) {
            if (--map[num] >= 0) {
                res.push_back(num);
            }
        }
        return res;
    }
};