//--- Q: 0526. Beautiful Arrangement

//--- method 1: swap and start from back
class Solution {
public:
    int res = 0;
    int countArrangement(int n) {
        vector<int> idx;
        for (int i = 1; i <= n; ++i) {
            idx.push_back(i);
        }
        dfs(idx.size()-1, idx);
        return res;
    }
    void dfs(int start, vector<int> &idx) {
        if (start == -1) {
            ++res;
            return;
        }
        for (int i = start; i >= 0; --i) {
            if (idx[i] % (start+1) == 0 || (start+1) % idx[i] == 0) {
                swap(idx[i], idx[start]);
                dfs(start-1, idx);
                swap(idx[i], idx[start]);
            }
        }
    }
};

//--- method 2: visit array and start from back
class Solution {
public:
    int res = 0;
    int countArrangement(int n) {
        vector<int> visit(n, 0);
        dfs(n, visit);
        return res;
    }
    void dfs(int val, vector<int> &visit) {
        if (val == 0) {
            ++res;
            return;
        }
        for (int i = visit.size()-1; i >= 0; --i) {
            if (!visit[i] && ((i+1)%val == 0 || val%(i+1) == 0)) {
                visit[i] = 1;
                dfs(val-1, visit);
                visit[i] = 0;
            }
        }
    }
};