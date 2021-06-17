//--- Q: 541. Reverse String II

//--- method 1: reverse string in k
class Solution {
public:
    string reverseStr(string s, int k) {
        int strlen = s.size();
        for (int i = 0; i < s.size();) {
            int len = min(k, strlen-i);
            for (int j = 0; j < len/2; ++j) {
                swap(s[i+j], s[i+len-j-1]);
            }
            i += len*2;
        }
        return s;
    }
};

//--- method 2: another view
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += k) {
            if (i+k <= s.size()) {
                reverse(s.begin()+i, s.begin()+i+k);
            } else {
                reverse(s.begin()+i, s.end());
            }
            i += k;
        }
        return s;
    }
};