//--- Q: 66. Plus One

//--- method 1: linear operation, O(n)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for (i = digits.size()-1; i >= 0; --i)
        {
        	if (digits[i] == 9)
        		digits[i] = 0;
        	else break;
        }
        if (i == -1)
        	digits.insert(digits.begin(), 1);
        else digits[i] += 1;
        return digits;
    }
};

//--- method 2:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int notnine = -1;
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] != 9) {
                notnine = i;
            }
        }
        if (notnine == -1) {
            for (auto &d: digits) {
                d = 0;
            }
            digits.insert(digits.begin(), 1);
        } else {
            ++digits[notnine];
            for (int i = notnine+1; i < digits.size(); ++i) {
                digits[i] = 0;
            }
        }
        return digits;
    }
};