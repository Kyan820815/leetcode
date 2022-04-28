//--- Q: 1999. Smallest Greater Multiple Made of Two Digits

//--- method 1: naive dfs
class Solution {
public:
    using ll = long long;
    int res = 0;
    int findInteger(int k, int digit1, int digit2) {
        if (digit1 > digit2) {
            swap(digit1, digit2);
        }
        vector<int> arr = {digit1};
        if (digit1 != digit2) {
            arr.push_back(digit2);
        }
        for (int i = 1; i <= 10; ++i) {
            if (dfs(i, k, arr, 0)) {
                return res;
            }
        }
        return -1;
    }
    bool dfs(int cnt, int k, vector<int> &arr, ll val) {
        if (val > maxv) {
            return false;
        }
        if (!cnt) {
            if (val > k && val % k == 0) {
                res = val;
                return true;
            }
            return false;            
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (dfs(cnt-1, k, arr, val*10+arr[i])) {
                return true;
            }
        }
        return false;
    }
};

//--- method 2: check digit
class Solution {
public:
    using ll = long long;
    int findInteger(int k, int digit1, int digit2, ll x = 0) {
        if (x > INT_MAX) {
            return -1;
        }
        if (x > k && x%k == 0) {
            return x;
        }
        int x1 = x+digit1 == 0 ? -1 : findInteger(k, digit1, digit2, x*10+digit1);
        int x2 = x+digit2 == 0 ? -1 : findInteger(k, digit1, digit2, x*10+digit2);
        return x1 > 0 && x2 > 0 ? min(x1, x2) : max(x1, x2);
    }
};