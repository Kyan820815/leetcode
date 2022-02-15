//--- Q: 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number

//--- method 1: next permutation and greedy two pointers
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string res = num;
        for (int i = 0; i < k; ++i) {
            findnext(res);
        }
        int n = num.size(), left = 0, cnt = 0;
        while (left < n) {
            int right = left;
            while (right < n && num[right] != res[left]) {
                ++right;
            }
            while (left != right) {
                swap(num[right], num[right-1]);
                --right;
                ++cnt;
            }
            ++left;
        }
        return cnt;
    }
    void findnext(string &num) {
        int n = num.size(), idx = n;
        for (int i = n-1; i > 0; --i) {
            if (num[i-1] < num[i]) {
                idx = i-1;
                break;
            }
        }
        int midx = idx;
        for (int i = idx+1; i < n; ++i) {
            if (num[i] > num[idx]) {
                midx = i;
            }
        }
        swap(num[idx], num[midx]);
        reverse(num.begin()+idx+1, num.end());
    }
};