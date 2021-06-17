//--- Q: 386. Lexicographical Numbers

//--- method 1: iteration
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            res.push_back(cur);
            if (cur*10 <= n) {
                cur *= 10;
            } else {
                if (cur == n) {
                    cur /= 10;
                }
                ++cur;
                while (cur%10 == 0) {
                    cur /= 10;
                }
            }
        }
        return res;
    }
};

//--- method 2: recursion
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i)
            recur(n, i, res);
        return res;
    }
    void recur(int n, int cur, vector<int> &res)
    {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++i)
        {
            if (cur*10 + i <= n)
                recur(n, cur*10 + i, res);
            else return;
        }
    }
};