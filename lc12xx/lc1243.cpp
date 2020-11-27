//--- Q: 1243. Array Transformation

//--- method 1: do transformation as much as we can, O(1) space
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool doprocess = true;
        while (doprocess) {
            doprocess = false;
            int prev = arr[0];
            for (int i = 1; i < arr.size()-1; ++i) {
                int tmp = arr[i];
                if (arr[i] > prev && arr[i] > arr[i+1]) {
                    --arr[i];
                    doprocess = true;
                } else if (arr[i] < prev && arr[i] < arr[i+1]) {
                    ++arr[i];
                    doprocess = true;
                }
                prev = tmp;
            }
        }
        return arr;
    }
};