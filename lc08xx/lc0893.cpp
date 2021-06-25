//--- Q: 893. Groups of Special-Equivalent Strings

//--- method 1: find patterns based on index
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        for (auto &str: A) {
            string upper = "", lower = "";
            for (int i = 0; i < str.size(); ++i) {
                if (i&1) {
                    lower.push_back(str[i]);
                } else {
                    upper.push_back(str[i]);
                }
            }
            sort(lower.begin(), lower.end());
            sort(upper.begin(), upper.end());
            str = lower + upper;
            if (set.find(str) == set.end()) {
                set.insert(str);
            }
        }
        return set.size();
    }
};