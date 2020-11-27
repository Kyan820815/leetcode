//--- Q: 1394. Find Lucky Integer in an Array

//--- method 1: bucket sort
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> bucket(501, 0);
        for (int i = 0; i < arr.size(); ++i) {
            ++bucket[arr[i]];
        }
        for (int i = 500; i >= 1; --i) {
            if (bucket[i] == i) {
                return i;
            }
        }
        return -1;
    }
};