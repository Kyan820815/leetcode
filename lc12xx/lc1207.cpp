//--- Q: 1207. Unique Number of Occurrences

//--- method 1: count occurences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> set;
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); ++i) {
            ++map[arr[i]];
        }
        for (auto &m: map) {
            if (set.find(m.second) == set.end()) {
                set.insert(m.second);
            } else {
                return false;
            }
        }
        return true;
    }
};