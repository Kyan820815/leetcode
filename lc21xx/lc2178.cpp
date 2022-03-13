//--- Q: 2178. Maximum Split of Positive Even Integers

//--- method 1: greedy choose smaller even number
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum&1) {
            return {};
        }
        vector<long long> res;
        long long num = 2;
        while (finalSum >= num) {
            finalSum -= num;
            res.push_back(num);
            num += 2;
        }
        res.back() += finalSum;
        return res;
    }
};