//--- Q: 0769. Max Chunks To Make Sorted

//--- method 1: linear seach i & arr[idx]
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 1, last = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            if (i > last) {
                ++res;
            }
            last = max(last, arr[i]);
        }
        return res;
    }
};