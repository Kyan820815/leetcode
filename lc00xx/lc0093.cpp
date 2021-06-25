//--- Q: 093. Restore IP Addresses

//--- method 1: recursion
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        dfs(0, s, "", 0);
        return res;
    }
    void dfs(int idx, string &s, string num_vec, int tcnt) {
        string num = "";
       if (tcnt == 4) {
            if (idx == s.size()) {
                num_vec.pop_back();
                res.push_back(num_vec);
            }
            return;
        }
        int cnt = 0;
        for (int i = idx; i < idx+3 && i < s.size(); ++i) {
            cnt = cnt * 10 + (s[i]-'0');
            num.push_back(s[i]);
            if (cnt <= 255 && s[idx] != '0' || s[idx] == '0' && i == idx) {
                dfs(i+1, s, num_vec+num+".", tcnt+1);
            } else {
                return;
            }
        }
    }
};

//--- method 2: find all possible solutions
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    for (int l = 1; l <= 3; ++l) {
                        if (i+j+k+l == s.size()) {
                            int I = stoi(s.substr(0, i));
                            int J = stoi(s.substr(i, j));
                            int K = stoi(s.substr(i+j, k));
                            int L = stoi(s.substr(i+j+k, l));
                            if (I <= 255 && J <= 255 && K <= 255 && L <= 255) {
                                string is = to_string(I);
                                string js = to_string(J);
                                string ks = to_string(K);
                                string ls = to_string(L);
                                string str = is + "." + js + "." + ks + "." + ls;
                                if (str.size() == s.size()+3) {
                                    res.push_back(str);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};