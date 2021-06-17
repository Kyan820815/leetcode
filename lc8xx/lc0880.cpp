//--- Q: 880. Decoded String at Index

//--- method 1: stack, O(n) space
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int idx = 0, tlen = 0;
        string now = "";
        --k;
        vector<pair<string, int>> sk;
        while (idx < s.size()) {
            if (isdigit(s[idx])) {
                int cnt = 1, process = 0;
                while (isdigit(s[idx])) {
                    cnt *= (s[idx++]-'0');
                    if (cnt*(tlen+now.size()) > k) {
                        process = 1;
                        break;
                    }
                }
                tlen += now.size();
                if (process) {
                    while (1) {
                        k = k%tlen;
                        if (k < tlen-now.size()) {
                            tlen = (tlen-now.size())/sk.back().second;
                            now = sk.back().first;
                            sk.pop_back();
                        } else {
                            tlen -= now.size();
                            k -= tlen;
                            return string()+now[k];
                        }
                    }
                } else {
                    tlen *= cnt;
                    sk.push_back({now, cnt});
                }
                now = "";
            } else {
                now += s[idx++];
            }
        }
        return string() + now[k];
    }
};

//--- method 2: work backward, O(1) space
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long N = 0, i;
        for (i = 0; N < k; ++i) {
            N = isdigit(s[i]) ? N*(s[i]-'0') : N+1;
        }
        while (--i >= 0) {
            if (isdigit(s[i])) {
                N /= (s[i]-'0');
                k %= N;
            } else {
                if (k == N || k == 0) {
                    break;
                }
                N--;
            }
        }
        return string() + s[i];
    }
};