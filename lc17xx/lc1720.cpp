//--- Q: 1720. Decode XORed Array

//--- method 1: a^b = c == a^c == b
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = {first};
        for (auto &val: encoded) {
            res.push_back(res.back()^val);
        }
        return res;
    }
};