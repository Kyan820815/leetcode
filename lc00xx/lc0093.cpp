//--- Q: 0093. Restore IP Addresses
//--- last written: 2023/07/08

//--- method 1: recursion
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 15) {
            return {};
        }
        dfs(0, 4, s, "");
        return res;
    }
    void dfs(int idx, int cnt, string &s, string ip) {
        if (!cnt) {
            if (idx == s.size()) {
                ip.pop_back();
                res.push_back(ip);
            }
            return;
        }
        string tmp = "";
        int len = min((int)s.size(), idx+3);
        for (int i = idx; i < len; ++i) {
            tmp += s[i];
            if (stoi(tmp) <= 255 && (i == idx && tmp[0] == '0' || tmp[0] != '0')) {
                dfs(i+1, cnt-1, s, ip+tmp+".");
            }
        }
    }
};

//--- method 2: find all possible solutions
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 15) {
            return {};
        }
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    for (int l = 1; l <= 3; ++l) {
                        if (i+j+k+l == s.size()) {
                            string is = s.substr(0, i);
                            string js = s.substr(i, j);
                            string ks = s.substr(i+j, k);
                            string ls = s.substr(i+j+k, l);
                            if (is.size() == 3 && is > "255" || js.size() == 3 && js > "255"
                               || ks.size() == 3 && ks > "255" || ls.size() == 3 && ls > "255") {
                                continue;
                            }
                            if (is[0] == '0' && is.size() != 1 || js[0] == '0' && js.size() != 1
                               || ks[0] == '0' && ks.size() != 1 || ls[0] == '0' && ls.size() != 1) {
                                continue;
                            }
                            res.push_back(is + "." + js + "." + ks + "." + ls);
                        }
                    }
                }
            }
        }
        return res;
    }
};
