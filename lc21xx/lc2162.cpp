//--- Q: 2162. Minimum Cost to Set Cooking Time

//--- method 1: find pattern
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        auto comp = [&](int pos, int m, int s) {
            if (m < 0 || m > 99 || s < 0 || s > 99) {
                return INT_MAX;
            }
            string str = to_string(m*100+s);
            int res = 0;
            for (auto &digit: str) {
                res += (digit-'0') != pos ? moveCost : 0;
                res += pushCost;
                pos = digit-'0';
            }
            return res;
        };
        int m = targetSeconds/60, s = targetSeconds%60;
        return min(comp(startAt, m, s), comp(startAt, m-1, s+60));
    }
};