//--- Q: 0394. Decode String

//--- method 1: dfs recursion
class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return dfs(idx, s);
    }
    string dfs(int &idx, string &s) {
        string res = "";
        int sum = 0;
        for (; idx < s.size();) {
            if (s[idx] == '[') {
                ++idx;
                auto rtn_str = dfs(idx, s);
                for (; sum; sum--) {
                    res += rtn_str;
                }
            } else if (s[idx] == ']') {
                ++idx;
                return res;
            } else if (isdigit(s[idx])) {
                sum = sum*10 + (s[idx++]-'0');
            } else {
                res += s[idx++];
            }
        }
        return res;
    }
};

//--- method 2: iterative stack
class Solution {
public:
    string decodeString(string s) {
        string cstr = "";
        int sum = 0;
        vector<pair<string, int>> sk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                sk.push_back({cstr, sum});
                sum = 0;
                cstr = "";
            } else if (s[i] == ']') {
                sum = sk.back().second;
                auto tmp = cstr;
                cstr = sk.back().first;
                for (; sum; sum--) {
                    cstr += tmp;
                }
                sk.pop_back();
            } else if (isdigit(s[i])) {
                sum = sum*10 + (s[i]-'0');
            } else {
                cstr += s[i];
            }
        }
        return cstr;
    }
};

//--- follow up:
string dfs(int &idx, string &s) {
    string res = "";
    for (; idx < s.size();) {
        if (s[idx] == '(') {
            ++idx;
            auto rtn_str = dfs(idx, s);
            int sum = 0;
            for (++idx; s[idx] != '}'; ++idx){
                sum = sum*10 + (s[idx]-'0');
            }
            for (; sum; --sum) {
                res += rtn_str;
            }
            ++idx;
        } else if (s[idx] == ')') {
            ++idx;
            return res;
        } else {
            res += s[idx++];
        }
    }
    return res;
}