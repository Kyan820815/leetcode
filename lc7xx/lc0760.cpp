//--- Q: 0760. Find Anagram Mappings

//--- method 1: map operation
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums2.size(); ++i) {
            map[nums2[i]].push_back(i);
        }
        vector<int> res;
        for (auto &num: nums1) {
            res.push_back(map[num].back());
            map[num].pop_back();
        }
        return res;
    }
};