//--- Q: 556. Next Greater Element III

//--- method 1: next permutation
class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.size(), idx = len;
        for (int i = len-1; i >= 1; --i) {
            if (num[i] > num[i-1]) {
                idx = i-1;
                break;
            }
        }
        if (idx == len) {
            return -1;
        }
        int maxidx;
        for (int i = idx+1; i < len; ++i) {
            if (num[i] > num[idx]) {
                maxidx = i;
            }
        }
        swap(num[idx], num[maxidx]);
        reverse(num.begin()+idx+1, num.end());
        int sum = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (sum > INT_MAX/10 || sum == INT_MAX/10 && num[i] > '7') {
                return -1;
            }
            sum = sum*10 + (num[i]-'0');
        }
        return sum;
    }
};