//--- Q: 0942. DI String Match

//--- method 1: outside in
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int left = 0, right = s.size();
        vector<int> res;
        for (auto &ch: s) {
            if (ch == 'I') {
                res.push_back(left++);
            } else {
                res.push_back(right--);
            }
        }
        res.push_back(left);
        return res;
    }
};

//--- method 2: inside out
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int left = 0;
        for (auto &ch: s) {
            left += ch == 'D';
        }
        vector<int> res = {left};
        int right = left;
        for (auto &ch: s) {
            if (ch == 'D') {
                res.push_back(--left);
            } else {
                res.push_back(++right);
            }
        }
        return res;
    }
};