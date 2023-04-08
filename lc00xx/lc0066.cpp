//--- Q: 0066. Plus One
//--- last written: 2023/04/04

//--- method 1: linear operation, O(n)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for (i = digits.size()-1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                break;
            }
        }
        if (i < 0) {
            digits.insert(digits.begin(), 1);
        } else {
            ++digits[i];
        }
        return digits;
    }
};
