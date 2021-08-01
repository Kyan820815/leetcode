//--- Q: 0599. Minimum Index Sum of Two Lists

//--- method 1: map operation
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minidx = 2000;
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); ++i) {
            map[list1[i]] = i;
        }
        vector<string> res;
        for (int i = 0; i < list2.size(); ++i) {
            if (map.find(list2[i]) != map.end()) {
                auto idx = i+map[list2[i]];
                if (idx < minidx) {
                    minidx = idx;
                    res = {list2[i]};
                } else if (idx == minidx) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};