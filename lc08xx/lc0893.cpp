//--- Q: 0893. Groups of Special-Equivalent Strings

//--- method 1: find patterns based on index
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> set;
        for (auto &word: words) {
            string odd = "", even = "";
            for (int i = 0; i < word.size(); ++i) {
                if (i&1) {
                    odd += word[i];
                } else {
                    even += word[i];
                }
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            if (set.find(odd+even) == set.end()) {
                set.insert(odd+even);
            }
        }
        return set.size();
    }
};