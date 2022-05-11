//--- Q: 1943. Describe the Painting

//--- method 1: map
class Solution {
public:
    using ll = long long;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,ll> m;
        for (auto &segment: segments) {
            m[segment[0]] += segment[2];
            m[segment[1]] -= segment[2];
        }
        vector<vector<ll>> res;
        ll curc = 0, last = -1;
        for (auto &[time, color]: m) {
            if (last != -1 && curc) {
                res.push_back({last, time, curc});
            }
            curc += color;
            last = time;
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    using ll = long long;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<ll> m(100001);
        vector<bool> end(100001);
        for (auto &segment: segments) {
            m[segment[0]] += segment[2];
            m[segment[1]] -= segment[2];
            end[segment[0]] = end[segment[1]] = true;
        }
        vector<vector<ll>> res;
        ll curc = 0, last = -1;
        for (int i = 1; i <= 100000; ++i) {
            if (!end[i]) {
                continue;
            }
            if (last != -1 && curc) {
                res.push_back({last, i, curc});
            }
            curc += m[i];
            last = i;
        }
        return res;
    }
};
