//--- Q: 1014. Best Sightseeing Pair

//--- method 1: record index of max value
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mi = 0, res = 0;
        for (int i = 1; i < values.size(); ++i) {
            res = max(res, values[mi]+values[i]-(i-mi));
            if (values[mi]-(i-mi) < values[i]) {
                mi = i;
            }
        }
        return res;
    }
};

//--- method 2: record max value
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int cur = 0, res = 0;
        for (int i = 0; i < values.size(); ++i) {
            res = max(res, cur+values[i]);
            cur = max(cur, values[i])-1;
        }
        return res;
    }
};