//--- Q: 1213. Intersection of Three Sorted Arrays

//--- method 1: three pointer
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0, j = 0, k = 0;
        vector<int> res;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                res.push_back(arr1[i]);
                ++i, ++j, ++k;
            } else {
                int maxv = max(arr1[i], max(arr2[j], arr3[k]));
                while (i < arr1.size() && arr1[i] < maxv) {
                    ++i;
                }
                while (j < arr2.size() && arr2[j] < maxv) {
                    ++j;
                }
                while (k < arr3.size() && arr3[k] < maxv) {
                    ++k;
                }
            }
        }
        return res;
    }
};