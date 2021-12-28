//--- Q: 0941. Valid Mountain Array

//--- method 1: one way check
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0, n = arr.size();
        while (i+1 < n && arr[i] < arr[i+1]) {
            ++i;
        }
        if (!i || i == n-1) {
            return false;
        }
        while (i+1 < n && arr[i] > arr[i+1]) {
            ++i;
        }
        return i == arr.size()-1;
    }
};