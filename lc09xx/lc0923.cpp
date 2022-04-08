//--- Q: 0923. 3Sum With Multiplicity

//--- method 1: sort then two pointers
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7, res = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n-2; ++i) {
            if (arr[i]+arr[i+1]+arr[i+2] > target) {
                break;
            }
            if (arr[i]+arr[n-2]+arr[n-1] < target) {
                continue;
            }
            int left = i+1, right = n-1, t = target-arr[i];
            while (left < right) {
                if (arr[left]+arr[right] < t) {
                    ++left;
                } else if (arr[left]+arr[right] > t) {
                    --right;
                } else {
                    int lc = 1, rc = 1, start = left;
                    while (left < right && arr[left] == arr[left+1]) {
                        ++left, ++lc;
                    }
                    if (left == right) {
                        res = (res+(right-start+1)*(right-start)/2) % mod;
                        break;
                    }
                    while (left < right && arr[right] == arr[right-1]) {
                        --right, ++rc;
                    }
                    res = (res+lc*rc) % mod;
                    ++left, --right;
                }
            }
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    using ll = long long;
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7, res = 0;
        vector<ll> cnt(101, 0);
        for (auto &v: arr) {
            ++cnt[v];
        }
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                int k = target-i-j;
                if (k < 0 || k > 100) {
                    continue;
                }
                if (i == j && j == k) {
                    res = (res+(cnt[i]*(cnt[i]-1)*(cnt[i]-2))/6) % mod;
                } else if (i == j && j != k) {
                    res = (res + (cnt[i]*(cnt[i]-1))/2*cnt[k]) % mod;
                } else if (i < j && j < k) {
                    res = (res + (cnt[i]*cnt[j]*cnt[k])) % mod;
                }
            }
        }
        return res;
    }
};

//--- method 3: no sort, count arr[i]+arr[j]
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7, res = 0, n = arr.size();
        unordered_map<int,int> map;
        for (int i = 0; i < n; ++i) {
            res = (res + map[target-arr[i]])%mod;
            for (int j = 0; j < i; ++j) {
                ++map[arr[i]+arr[j]];
            }
        }
        return res;
    }
};