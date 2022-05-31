//--- Q: 1461. Check If a String Contains All Binary Codes of Size K

//--- method 1: bit manipulation
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> set;
        int val = 0;
        for (int i = 0; i < k && i < s.size(); ++i) {
            val = (val << 1) | (s[i]-'0');
        }
        set.insert(val);
        for (int i = k; i < s.size(); ++i) {
            val = ((val << 1) | (s[i]-'0')) & ((1<<k)-1);
            set.insert(val);
        }
        return set.size() == (1<<k);
    }
};