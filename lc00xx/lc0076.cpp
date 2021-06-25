//--- Q: 076. Minimum Window Substring

//--- method 1: sliding window:
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, res_minv = INT_MAX, cnt = 0;
        string res_str = "";
        vector<int> str(128, 0);
        for (int i = 0; i < t.size(); ++i)
            ++str[t[i]];
        for (int i = 0; i < s.size(); ++i) {
            if (--str[s[i]] >= 0)
                ++cnt;
            if (cnt == t.size()) {
                while (str[s[left]] < 0)
                    ++str[s[left++]];
                if (i-left+1 < res_minv) {
                    res_minv = i-left+1;
                    res_str = s.substr(left, res_minv);
                }
            }
        }
        return res_str;
    }
};

//--- method 2: faster code based on method 1
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, res_minv = INT_MAX, cnt = 0, head = 0;
        vector<int> str(128, 0);
        for (int i = 0; i < t.size(); ++i)
            ++str[t[i]];
        bool find = false;
        for (int i = 0; i < s.size(); ++i) {
            if (--str[s[i]] >= 0)
                ++cnt;
            while (cnt == t.size()) {
                if (++str[s[left++]] > 0) {
                    --cnt;
                    find = true;
                }
            }
            if (find && i-(left-1)+1 < res_minv) {
                res_minv = i-(left-1)+1;
                head = left-1;
                find = false;
            }
        }
        return res_minv == INT_MAX ? "" : s.substr(head, res_minv);
    }
};