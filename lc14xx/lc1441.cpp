//--- Q: 1441. Build an Array With Stack Operations

//--- method 1: update current number
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int now = 1;
        for (int i = 0; i < target.size(); ++i) {
            while (target[i] > now) {
                res.push_back("Push");
                res.push_back("Pop");
                now++;
            }
            res.push_back("Push");
            ++now;
        }
        return res;
    }
};