//--- Q: 349. Intersection of Two Arrays

//--- method 1: unordered_map solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i)
        {
            if (set.find(nums1[i]) == set.end())
                set.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (set.find(nums2[i]) != set.end())
            {
                res.push_back(nums2[i]);
                set.erase(nums2[i]);
            }
        }
        return res;
    }
};