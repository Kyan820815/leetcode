//--- Q: 0768. Max Chunks To Make Sorted II

//--- method 1: O(n) space
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> min_arr(arr.size()), max_arr(arr.size());
        int minv = INT_MAX, maxv = INT_MIN;
        for (int i = 0, j = arr.size()-1; i < arr.size(); ++i, --j) {
            maxv = max(maxv, arr[i]);
            minv = min(minv, arr[j]);
            max_arr[i] = maxv;
            min_arr[j] = minv;
        }
        int res = 1;
        for (int i = 0; i < arr.size()-1; ++i) {
            res += max_arr[i] <= min_arr[i+1];
        }
        return res;
    }
};

//--- method 2: stack
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sk;
        for (auto &num: arr) {
            if (sk.size() && sk.back() > num) {
                auto maxv = sk.back();
                sk.pop_back();
                while (sk.size() && sk.back() > num) {
                    sk.pop_back();
                }
                sk.push_back(maxv);
            } else {
                sk.push_back(num);
            }
        }
        return sk.size();
    }
};