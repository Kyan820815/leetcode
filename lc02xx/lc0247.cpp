//--- Q: 0247. Strobogrammatic Number II

//--- method 1: dfs with n from large to small
class Solution {
public:
    vector<string> res;
    vector<string> findStrobogrammatic(int n) {
        string str(n, '.');
        dfs(0, n-1, str);
        return res;
    }
    void dfs(int left, int right, string &num) {
        if (left > right) {
            res.push_back(num);
            return;            
        }
        if (num.size() == 1 || left) {
            num[left] = num[right] = '0';
            dfs(left+1, right-1, num);
        }

        num[left] = num[right] = '1';
        dfs(left+1, right-1, num);

        num[left] = num[right] = '8';
        dfs(left+1, right-1, num);

        if (left != right) {
            num[left] = '6', num[right] = '9';
            dfs(left+1, right-1, num);

            num[left] = '9', num[right] = '6';
            dfs(left+1, right-1, num);
        }
    }
};