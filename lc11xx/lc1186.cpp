//--- Q: 1186. Maximum Subarray Sum with One Deletion

//--- method 1: two subarray
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int maxNoDelete = arr[0], maxWithDelete = arr[0], maxv = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            maxWithDelete = max(maxNoDelete, maxWithDelete+arr[i]);
            maxNoDelete = max(maxNoDelete+arr[i], arr[i]);
            maxv = max(maxv, max(maxNoDelete, maxWithDelete));
        }
        return maxv;
    }
};