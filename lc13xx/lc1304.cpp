//--- Q: 1304. Find N Unique Integers Sum up to Zero

//--- method 1: find rule, better
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(i*2 - (n-1));
        }
        return res;
    }
};

//--- method 2: add complement
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for (int i = 1; i <= n/2; ++i) {
            res.push_back(i);
            res.push_back(i*-1);
        }
        if (n&1) {
            res.push_back(0);
        }
        return res;
    }
};