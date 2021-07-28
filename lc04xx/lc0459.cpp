//--- Q: 0459. Repeated Substring Pattern

//--- method 2: use lenth to count repeated subdstring
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size()/2; ++i) {
            if (s.size()%i == 0 && s.substr(i) == s.substr(0,s.size()-i)) {
                return true;
            }
        }
        return false;
    }
};

//--- method 2: next of KMP
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size()+1, -1);
        for (int i = 0, j = -1; i < s.size();) {
            if (j == -1 || s[j] == s[i]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        return next.back() != 0 && s.size()%(s.size()-next.back()) == 0;
    }
};