//--- Q: 1200. Minimum Absolute Difference

//--- method 1: bucket sort
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        vector<int> cnt(2*1000000+1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            ++cnt[arr[i]+1000000];
        }
        int last = -cnt.size(), minv = INT_MAX, shift = 1000000;
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i]) {
                if (i-last < minv) {
                    minv = i-last;
                    res = {{last-shift, i-shift}};
                } else if (i-last == minv) {
                    res.push_back({last-shift, i-shift});
                }
                last = i;
            }
        }
        return res;
    }
};

//--- method 2: nlogn sort
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int last = -2000001, minv = INT_MAX;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i]-last < minv) {
                minv = arr[i]-last;
                res = {{last, arr[i]}};
            } else if (arr[i]-last == minv) {
                res.push_back({last, arr[i]});
            }
            last = arr[i];
        }
        return res;
    }
};