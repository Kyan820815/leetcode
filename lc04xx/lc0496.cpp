//--- Q: 0496. Next Greater Element I

//--- method 1: stack iteration with map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1), sk;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); ++i) {
            map[nums1[i]] = i;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            while (sk.size() && nums2[sk.back()] < nums2[i]) {
                if (map.find(nums2[sk.back()]) != map.end()) {
                    res[map[nums2[sk.back()]]] = nums2[i];
                }
                sk.pop_back();
            }
            sk.push_back(i);
        }
        return res;
    }
};