//--- Q: 541. Reverse String II

//--- method 1: reverse string in k
class Solution {
public:
    string reverseStr(string s, int k) {
        int strlen = s.size();
        for (int i = 0; i < s.size();)
        {
            int len = min(k, strlen-i);
            for (int j = 0; j < len/2; ++j)
                swap(s[i+j], s[i+len-j-1]);
            i += len*2;
        }
        return s;
    }
};