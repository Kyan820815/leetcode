//--- Q: 1013. Partition Array Into Three Parts With Equal Sum

//--- method 1: find target 3 times
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
        }
        if (sum % 3 != 0) {
            return false;
        }
        int target = sum/3, now = 0, times = 0;
        for (int i = 0; i < A.size(); ++i) {
            now += A[i];
            if (now == target) {
                now = 0;
                ++times;
            }
        }
        return times >= 3;
    }
};