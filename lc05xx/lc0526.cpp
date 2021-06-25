//--- Q: 526. Beautiful Arrangement

//--- method 1: visit array and start from head
class Solution {
public:
    int res = 0;
    int countArrangement(int n) {
        vector<int> used(n+1, 0);
        dfs(1, used);
        return res;
    }
    void dfs(int now, vector<int> &used) {
        if (now == used.size()) {
            ++res;
            return;
        }
        for (int i = 1; i < used.size(); ++i) {
            if (used[i] == 0 && (i%now == 0 || now%i == 0)) {
                used[i] = 1;
                dfs(now+1, used);
                used[i] = 0;
            }
        }
    }
};

//--- method 2: swap and start from back
class Solution {
public:
    int countArrangement(int n) {
        vector<int> arr = {0};
        for (int i = 1; i <= n; ++i) {
            arr.push_back(i);
        }
        return dfs(n, arr);
    }
    int dfs(int idx, vector<int> &arr) {
        if (idx == 0) {
            return 1;
        }
        int cnt = 0;
        for (int i = idx; i >= 1; --i) {
            if (idx%arr[i] == 0 || arr[i]%idx == 0) {
                swap(arr[idx], arr[i]);
                cnt += dfs(idx-1, arr);
                swap(arr[idx], arr[i]);
            }
        }
        return cnt;
    }
};