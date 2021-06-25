//--- Q: 1684. Count the Number of Consistent Strings

//--- method 1: set
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set(allowed.begin(), allowed.end());
        int res = words.size();
        for (auto &wd: words) {
            int cnt = 0;
            for (auto &ch: wd) {
                if (set.find(ch) == set.end()) {
                    --res;
                    break;
                }
                ++cnt;
            }
        }
        return res;
    }
};