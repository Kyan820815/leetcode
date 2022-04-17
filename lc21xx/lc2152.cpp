//--- Q: 2152. Minimum Number of Lines to Cover Points

//--- method 1: dp recursion
class Solution {
public:
    vector<vector<int>> dp;
    vector<map<pair<int,int>, int>> map;
    int minimumLines(vector<vector<int>>& points) {
        int n = points.size();
        dp.resize(n, vector<int>(1<<n, 0));
        map.resize(n);
        auto slope = [](const vector<int> &a, const vector<int> &b) {
            int dx = a[0]-b[0], dy = a[1]-b[1];
            int g = gcd(dx, dy);
            int f = dx* dy >= 0 ? 1 : -1;
            return pair<int,int>{f*abs(dx/g), abs(dy/g)};
        };
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                map[i][slope(points[i], points[j])] |= (1<<i) | (1<<j);
            }
        }
        int mask = (1 << n) - 1;
        return dfs(n-1, mask);
    }
    int dfs(int i, int mask) {
        if (dp[i][mask] != 0) {
            return dp[i][mask];
        }
        if (!i) {
            int cnt = 0;
            while (mask) {
                mask &= (mask-1);
                ++cnt;
            }
            return (int)ceil((double)cnt/2);
        }
        if (!(mask & (1<<i))) {
            return dfs(i-1, mask);
        }
        int maxv = INT_MAX;
        for (auto &slope: map[i]) {
            maxv = min(maxv, 1+dfs(i-1, mask&(~slope.second)));
        }
        return dp[i][mask] = maxv;
    }
};

//--- method 2: iteration with trying all combinations of kines
class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<double,double>, int> map;
        auto slope = [](const vector<int> &p1, const vector<int> &p2) {
            if (p1[0] == p2[0]) {
                return pair<double,double>{p1[0], -1000};
            } else {
                double dx = p2[0]-p1[0], dy = p2[1]-p1[1];
                double a = dy/dx;
                double b = p1[1]-a*p1[0];
                return pair<double,double>{a,b};
            }
        };
        auto count = [](const int &val) {
            int cnt = 0, v = val;
            while (v) {
                v &= (v-1);
                ++cnt;
            }
            return cnt;
        };
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                map[slope(points[i], points[j])] |= (1<<i) | (1<<j);
            }
        }
        vector<int> lines;
        for (auto &m: map) {
            if (count(m.second) > 2) {
                lines.push_back(m.second);
            }
        }
        int mask = (1 << lines.size()) - 1, res = ceil((double)n/2);
        for (int i = 1; i <= mask; ++i) {
            int linecnt = 0, m = i, ptcnt = 0, j = 0, pt = 0;
            while (m) {
                if (m&1) {
                    ++linecnt;
                    pt |= lines[j];
                }
                ++j;
                m >>= 1;
            }
            ptcnt = count(pt);
            res = min(res, linecnt+(int)ceil((double)(n-ptcnt)/2));
        }
        return res;
    }
};