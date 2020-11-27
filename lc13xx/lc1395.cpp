//--- Q: 1395. Count Number of Teams

//--- method 1: O(n^3)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 0; i < rating.size(); ++i) {
            less = 0;
            dfs(i, rating, res, 1, rating[i]);
            less = 1;
            dfs(i, rating, res, 1, rating[i]);
        }
        return res;
    }
    void dfs(int now, vector<int> &rating, int &res, int size, int last) {
        if (size == 3) {
            ++res;
            return;
        }
        for (int i = now; i < rating.size(); ++i) {
            if (less && last < rating[i] || !less && last > rating[i]) {
                dfs(i+1, rating, res, size+1, rating[i]);
            }
        }
    }
    int less;
};

//--- method 2: O(n^2)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 1; i < rating.size()-1; ++i) {
            vector<int> less(2,0), greater(2,0);
            for (int j = 0; j < rating.size(); ++j) {
                if (rating[j] < rating[i]) {
                    less[j < i]++;
                }
                if (rating[j] > rating[i]) {
                    greater[j < i]++;
                }
            }
            res += less[0] * greater[1] + greater[0] * less[1];
        }
        return res;
    }
};