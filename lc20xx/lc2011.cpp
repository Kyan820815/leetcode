//--- Q: 2011. Final Value of Variable After Performing Operations

//--- method 1: find pattern
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (auto &operation: operations) {
            res += operation[1] == '+' ? 1 : -1;
        }
        return res;
    }
};