//--- Q: 1010. Pairs of Songs With Total Durations Divisible by 60

//--- method 1: map with two sum
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        unordered_map<int,int> map;
        for (auto &t: time) {
            int val = t%60;
            res += map[(60-val)%60];
            ++map[val];
        }
        return res;
    }
};