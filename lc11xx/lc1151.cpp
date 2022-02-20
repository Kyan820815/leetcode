//--- Q: 1151. Minimum Swaps to Group All 1's Together

//--- method 1: sliding window
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for (auto &v: data) {
            ones += v;
        }
        int left = 0, right = 0, res = INT_MAX, subones = 0;
        while (right < data.size()) {
            subones += data[right];
            if (right-left+1 > ones) {
                subones -= data[left++];
            }
            if (right-left+1 == ones) {
                res = min(res, right-left+1-subones);
            }
            ++right;
        }
        return res;
    }
};

//--- method 2: prefix sum
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        for (int i = 1; i < n; ++i) {
            data[i] += data[i-1];
        }
        if (!data.back()) {
            return 0;
        }
        int ones = data.back(), res = ones-data[ones-1];
        for (int i = ones; i < n; ++i) {
            res = min(res, ones-(data[i]-data[i-ones]));
        }
        return res;
    }
};