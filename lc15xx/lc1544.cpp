//--- Q: 1544. Make The String Great

//--- method 1: O(n) space
class Solution {
public:
    string makeGood(string s) {
        string res = "";
        for (auto &ch: s) {
            if (res.size() && (res.back()^32) == ch) {
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};

//--- method 2: O(1) space
class Solution {
public:
    string makeGood(string s) {
        int j = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (j >= 0 && (s[j]^s[i]) == 32) {
                --j;
            } else {
                s[++j] = s[i];
            }
        }
        return s.substr(0, j+1);
    }
};