//--- Q: 0760. Find Anagram Mappings

//--- method 1: map operation
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> map;
        vector<int> res;
        for (int i = 0; i < nums2.size(); ++i) {
            map[nums2[i]].push_back(i);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            res.push_back(map[nums1[i]].back());
            map[nums1[i]].pop_back();
        }
        return res;
    }
};