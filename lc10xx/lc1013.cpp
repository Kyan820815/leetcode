//--- Q: 1013. Partition Array Into Three Parts With Equal Sum

//--- method 1: find target 3 times
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (auto &num: arr) {
            sum += num;
        }
        if (sum%3 != 0) {
            return false;
        }
        auto partv = sum/3, cnt = 0, curs = 0;
        for (int i = 0; i < arr.size(); ++i) {
            curs += arr[i];
            if (curs == partv) {
                curs = 0;
                if (++cnt == 3) {
                    return true;
                }
            }
        }
        return false;
    }
};