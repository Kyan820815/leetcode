//--- Q: 1186. Maximum Subarray Sum with One Deletion

//--- method 1: two subarray
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int maxWithDel = arr[0], maxWithNoDel = arr[0], res = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            maxWithDel = max(maxWithNoDel, maxWithDel+arr[i]);
            maxWithNoDel = max(arr[i], maxWithNoDel+arr[i]);
            res = max(res, max(maxWithDel, maxWithNoDel));
        }
        return res;
    }
};