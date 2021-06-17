//--- Q: 1209. Remove All Adjacent Duplicates in String II

//--- method 1: stack iteration
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> sk;
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (sk.size() && sk.back().first == s[i]) {
                if (++sk.back().second == k) {
                    sk.pop_back();
                }
            } else {
                sk.push_back({s[i], 1});
            }
        }
        for (int i = 0; i < sk.size(); ++i) {
            for (int j = 0; j < sk[i].second; ++j) {
                res.push_back(sk[i].first);
            }
        }
        return res;
    }
};

//--- follow up >= k
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> sk;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (sk.size() && sk.back().first != s[i]) {
                if (sk.back().second >= k) {
                    sk.pop_back();
                }
            }
            if (sk.size() && sk.back().first == s[i]) {
                ++sk.back().second;
            } else {
                sk.push_back({s[i], 1});
            }
        }
        if (sk.size() && sk.back().second >= k) {
            sk.pop_back();
        }
        for (int i = 0; i < sk.size(); ++i) {
            for (int j = 0; j < sk[i].second; ++j) {
                res.push_back(sk[i].first);
            }
        }
        return res;
    }
};