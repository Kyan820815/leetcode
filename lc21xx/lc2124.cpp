//--- Q: 2124. Check if All A's Appears Before All B's

//--- method 1: check if there is b right before a
class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for (int i = 0; i < n-1; ++i) {
            if (s[i] > s[i+1]) {
                return false;
            }
        }
        return true;
    }
};