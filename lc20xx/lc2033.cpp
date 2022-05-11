//--- Q: 2033. Minimum Operations to Make a Uni-Value Grid

//--- method 1: find median
class Solution {
public:
    using ll = long long;
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int find = 1, rem = grid[0][0]%x, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row && find; ++i) {
            for (int j = 0; j < col && find; ++j) {
                if (grid[i][j]%x != rem) {
                    find = 0;
                }
                arr.push_back(grid[i][j]);
            }
        }
        if (!find) {
            return -1;
        }
        int n = arr.size(), mid = n/2, res = 0;
        nth_element(arr.begin(), arr.begin()+mid, arr.end());
        for (int i = 0; i < n; ++i) {
            res += abs(arr[mid]-arr[i])/x;
        }
        return res;
    }
};

//--- method 2: sort and prefix sum
class Solution {
public:
    using ll = long long;
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int find = 1, rem = grid[0][0]%x, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row && find; ++i) {
            for (int j = 0; j < col && find; ++j) {
                if (grid[i][j]%x != rem) {
                    find = 0;
                }
                arr.push_back(grid[i][j]);
            }
        }
        if (!find) {
            return -1;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<ll> leftv(n+1, 0), rightv(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i) {
                leftv[i] = leftv[i-1] + (ll)i*(arr[i]-arr[i-1])/x;
            }
        }
        ll res = LONG_MAX, right = 0;
        for (int i = n-1; i >= 0; --i) {
            if (i < n-1) {
                right += (ll)(n-i-1)*(arr[i+1]-arr[i])/x;
            }
            res = min(res, leftv[i]+right);
        }
        return res;
    }
};