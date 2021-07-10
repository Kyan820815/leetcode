//--- Q: 0248. Strobogrammatic Number III

//--- method 1: fill with given size
class Solution {
public:
    int res = 0, ll, rl;
    int strobogrammaticInRange(string low, string high) {
        ll = low.size(), rl = high.size();
        for (int i = ll; i <= rl; ++i) {
            string str(i, '.');
            dfs(0, i-1, str, low, high);
        }
        return res;
    }
    void dfs(int left, int right, string &str, string &low, string &high) {
        if (left > right) {
            if (str.size() == low.size() && str < low
               || str.size() == high.size() && str > high) {
                return;
            }
            ++res;
        } else {
            if (str.size() == 1 || left) {
                str[left] = str[right] = '0';
                dfs(left+1, right-1, str, low, high);
            }
            str[left] = str[right] = '1';
            dfs(left+1, right-1, str, low, high);

            str[left] = str[right] = '8';
            dfs(left+1, right-1, str, low, high);

            if (left < right) {
                str[left] = '6', str[right] = '9';
                dfs(left+1, right-1, str, low, high);
                str[left] = '9', str[right] = '6';
                dfs(left+1, right-1, str, low, high);
            }
        }
    }
};