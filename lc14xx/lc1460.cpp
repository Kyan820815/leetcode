//--- Q: 1460. Make Two Arrays Equal by Reversing Sub-arrays

//--- method 1: bucket sort
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001, 0);
        for (int i = 0; i < target.size(); ++i) {
            ++cnt[target[i]];
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (--cnt[arr[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: O(1) xor
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int t = 0, sum = 0;
        for (int i = 0; i < target.size(); ++i) {
            t ^= target[i];
            sum += target[i];
        }
        for (int i = 0; i < arr.size(); ++i) {
            t ^= arr[i];
            sum -= arr[i];
        }
        return !t && !sum;
    }
};