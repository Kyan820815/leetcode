//--- Q: 2176. Count Equal and Divisible Pairs in an Array

//--- method 1: naive brute force n^2
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<vector<int>> cnt(101);
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]].push_back(i);
        }
        int res = 0;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 0; j < cnt[i].size(); ++j) {
                for (int m = j+1; m < cnt[i].size(); ++m) {
                    if ((cnt[i][j]*cnt[i][m])%k == 0) {
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};

//--- method 2: nsqrt(n), use gcd
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<vector<int>> cnt(101);
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]].push_back(i);
        }
        int res = 0;
        for (int i = 1; i <= 100; ++i) {
            unordered_map<int, int> gcdmap;
            for (int j = 0; j < cnt[i].size(); ++j) {
                int gcdi = gcd(cnt[i][j], k);
                for (auto &[gcdj, cnt]: gcdmap) {
                    if (gcdi*gcdj%k == 0) {
                        res += cnt;
                    }
                }
                ++gcdmap[gcdi];
            }
        }
        return res;
    }
};