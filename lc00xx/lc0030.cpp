//--- Q: 0030. Substring with Concatenation of All Words
//--- last written: 2023/07/02

//--- method 1: map record
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto &word: words) {
            ++cnt[word];
        }
        vector<int> res;
        int n = s.size(), wdlen = words[0].size(), wdcnt = words.size(), totallen = wdlen * wdcnt;
        for (int i = 0; i <= n-totallen; ++i) {
            unordered_map<string, int> seen;
            int j;
            for (j = i; j < i+totallen; j+=wdlen) {
                string cword = s.substr(j,wdlen);
                if (cnt.find(cword) == cnt.end() || ++seen[cword] > cnt[cword]) {
                    break;
                }
            }
            if (j == i+totallen) {
                res.push_back(i);
            }
        }
        return res;
    }
};

//--- method 2: sliding window
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto &word: words) {
            ++cnt[word];
        }
        vector<int> res;
        int n = s.size(), wdlen = words[0].size();
        int kind = cnt.size();
        for (int i = 0; i < wdlen; ++i) {
            int left = i, right = i, ckind = 0;
            unordered_map<string, int> seen;
            while (right < n) {
                string cword = s.substr(right, wdlen);
                if (cnt.find(cword) == cnt.end()) {
                    seen.clear();
                    left = right+wdlen;
                    ckind = 0;
                } else {
                    ckind += ++seen[cword] == cnt[cword];
                    while (seen[cword] > cnt[cword]) {
                        string removeword = s.substr(left, wdlen);
                        ckind -= --seen[removeword] == cnt[removeword]-1;
                        left += wdlen;
                    }
                    if (ckind == kind) {
                        res.push_back(left);
                    }
                }
                right += wdlen;
            }
        }
        return res;
    }
};
