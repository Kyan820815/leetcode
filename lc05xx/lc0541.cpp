//--- Q: 0541. Reverse String II

//--- method 1: reverse string in k
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2*k) {
            int edge = min(n, i+k);
            for (int l = i, r = edge-1; l < r; ++l, --r) {
                swap(s[l], s[r]);
            }
        }
        return s;
    }
};