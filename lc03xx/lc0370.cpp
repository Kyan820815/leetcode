//--- Q: 0370. Range Addition

//--- method 1: prefix sum
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        for (auto &update: updates) {
            arr[update[0]] += update[2];
            if (update[1]+1 < length) {
                arr[update[1]+1] -= update[2];
            }
        }
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += arr[i];
            arr[i] = sum;
        }
        return arr;
    }
};