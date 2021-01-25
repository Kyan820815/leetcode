//--- Q: 821. Shortest Distance to a Character

//---method 1: two pass, O(1) space
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size(), lastloc = -n;
        vector<int> res(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                lastloc = i;
            }
            res[i] = min(res[i], i-lastloc);
        }
        for (int i = lastloc-1; i >= 0; --i) {
            if (S[i] == C) {
                lastloc = i;
            } else {
                res[i] = min(res[i], lastloc-i);
            }
        }
        return res;
    }
};

//--- method 2: additional array to store idx, two pointer
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.size();
        vector<int> idx = {-len}, res;
        for (int i = 0; i < len; ++i) {
            if (S[i] == C) {
                idx.push_back(i);
            }
        }
        idx.push_back(2*len);
        int left = 0, right = 1;
        while (left < len) {
            if (left <= idx[right]) {
                int minval = min(left-idx[right-1], idx[right]-left);
                res.push_back(minval);
                ++left;
            } else {
                ++right;
            }
        }
        return res;
    }
};