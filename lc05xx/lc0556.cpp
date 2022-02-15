//--- Q: 0556. Next Greater Element III

//--- method 1: next permutation
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), start = len;
        for (int i = len-1; i > 0; --i) {
            if (str[i] > str[i-1]) {
                start = i-1;
                break;
            }
        }
        if (start == len) {
            return -1;
        }
        int last;
        for (int i = start+1; i < len; ++i) {
            if (str[i] > str[start]) {
                last = i;
            }
        }
        swap(str[start], str[last]);
        reverse(str.begin()+start+1, str.end());
        int sum = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (sum > INT_MAX/10 || sum == INT_MAX/10 && str[i] > '7') {
                return -1;
            }
            sum = sum*10 + (str[i]-'0');
        }
        return sum;
    }
};