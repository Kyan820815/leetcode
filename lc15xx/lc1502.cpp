//--- Q: 1502. Can Make Arithmetic Progression From Sequence

//--- method 1: O(n) find self postion
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int minv = INT_MAX, maxv = INT_MIN, n = arr.size();
        for (int i = 0; i < n; ++i) {
            minv = min(minv, arr[i]);
            maxv = max(maxv, arr[i]);
        }
        if ((maxv-minv) % (n-1) != 0) {
            return false;
        }
        int diff = (maxv-minv) / (n-1), idx = 0;
        while (idx < n) {
            if (minv+idx*diff == arr[idx]) {
                ++idx;
            } else if ((arr[idx]-minv) % diff != 0) {
                return false;
            } else {
                int pos = (arr[idx]-minv) / diff;
                if (pos < idx || arr[pos] == arr[idx]) {
                    return false;
                }
                swap(arr[idx], arr[pos]);
            }
        }
        return true;
    }
};

//--- method 2: sort then find difference
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1]-arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if (d != arr[i]-arr[i-1]) {
                return false;
            }
        }
        return true;
    }
};