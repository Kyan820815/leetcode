//--- Q: 670. Maximum Swap

//--- method 1: find the last pair that num[i] < num[maxi]
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size(), maxi = n-1, left = -1, right;
        for (int i = n-2; i >= 0; --i) {
            if (str[maxi] > str[i]) {
                left = i, right = maxi;
            } else if (str[maxi] < str[i]) {
                maxi = i;
            }
        }
        if (left != -1) {
            swap(str[left], str[right]);
        }
        return stoi(str);
    }
};
