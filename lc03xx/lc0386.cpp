//--- Q: 0386. Lexicographical Numbers

//--- method 1: iteration
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int now = 1;
        for (int i = 0; i < n; ++i) {
            res.push_back(now);
            if (now*10 <= n) {
                now *= 10;
            } else {
                if (now == n) {
                    now /= 10;
                }
                ++now;
                while (now % 10 == 0) {
                    now /= 10;
                }
            }
        }
        return res;
    }
};