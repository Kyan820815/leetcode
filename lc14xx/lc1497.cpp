//--- Q: 1497. Check If Array Pairs Are Divisible by k

//--- method 1: one pass
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        int res = 0;
        for (auto &num: arr) {
            int rem = (num%k+k)%k;
            int other = (k-rem)%k;
            if (cnt[other]) {
                --cnt[other];
                ++res;
            } else {
                ++cnt[rem];
            }
        }
        return res == arr.size()/2;
    }
};

//--- method 2: bucket preprocessing, two pass
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> map(k);
        for (auto &num: arr) {
            ++map[(num%k+k)%k];
        }
        for (int i = 0; i <= k/2; ++i) {
            int pair = (k-i)%k;
            if (i != pair && map[i] != map[pair] || i == pair && (map[i]&1)) {
                return false;
            }
        }
        return true;
    }
};