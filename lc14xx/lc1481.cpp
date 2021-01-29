//--- Q: 1481. Least Number of Unique Integers after K Removals

//--- method 1: sort
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end()) {
                ++cnt;
            }
            ++mp[arr[i]];
        }
        sort(arr.begin(), arr.end(), [&mp](int a, int b) {
            return mp[a] < mp[b] || mp[a] == mp[b] && a < b;
        });
        for (int i = 0; i < arr.size() && k; ++i, --k) {
            if (!--mp[arr[i]]) {
                --cnt;
            }
        }
        return cnt;
    }
};

//--- method 2: heap
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i) {
            ++mp[arr[i]];
        }
        priority_queue<int, vector<int>, greater<int>> que;
        for (auto &m: mp) {
            que.push(m.second);
        }
        while (que.size() && k) {
            auto now = que.top();
            if (now <= k) {
                k -= now;
                que.pop();
            } else {
                break;
            }
        }
        return que.size();
    }
};

//--- method 3: bucket sort O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size(), uni = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end()) {
                ++uni;
            }
            ++mp[arr[i]];
        }
        vector<int> cnt(n+1, 0);
        for (auto &m: mp) {
            ++cnt[m.second];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (k >= i) {
                    k -= i;
                    --uni;
                } else {
                    return uni;
                }
            }
        }
        return uni;
    }
};