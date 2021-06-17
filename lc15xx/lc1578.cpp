//--- Q: 1578. Minimum Deletion Cost to Avoid Repeating Letters

//--- method 1:
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, maxv = cost[0], sum = cost[0];
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[i-1]){
                res += sum-maxv;
                if (i == s.size()) {
                    break;
                }
                sum = maxv = 0;
            }
            maxv = max(maxv, cost[i]);
            sum += cost[i];
        }
        return res;
    }
};