//--- Q: 248. Strobogrammatic Number III

//--- method 1: count when now.size() == len
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        vector<string> map({"11", "88", "00", "69", "96"});
        int res = 0;
        for (int i = low.size(); i <= high.size(); ++i) {
            dfs(i, low, high, "", res, map);
            dfs(i, low, high, "0", res, map);
            dfs(i, low, high, "1", res, map);
            dfs(i, low, high, "8", res, map);
        }
        return res;
    }
    void dfs(int len, string &low, string &high, string now, int &res, vector<string> &map) {
        if (now.size() < len-1) {
            for (int k = 0; k < 5; ++k) {
                dfs(len, low, high, map[k][0] + now + map[k][1], res, map);
            }
        } else if (now.size() == len) {
            if ((len != 1 && now[0] == '0')
                || (now.size() == low.size() && now.compare(low) < 0) 
                || (now.size() == high.size() && now.compare(high) > 0))
                return;
            ++res;
        }
    }
};

//--- method 2: fill with given size
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        for (int i = low.size(); i <= high.size(); ++i) {
            string now(i, '0');
            dfs(0, i-1, now, low, high, res);
        }
        return res;
    }
    void dfs(int left, int right, string &now, string &low, string &high, int &res) {
        if (left > right) {
            if (now.size() == low.size() && now.compare(low) < 0 || now.size() == high.size() && now.compare(high) > 0) {
                return;
            }
            ++res;
            return;
        }
        if (now.size() == 1 || left) {
            now[left] = '0';
            now[right] = '0';
            dfs(left+1, right-1, now, low, high, res);
        }
        now[left] = '8';
        now[right] = '8';
        dfs(left+1, right-1, now, low, high, res);
        now[left] = '1';
        now[right] = '1';
        dfs(left+1, right-1, now, low, high, res);
        
        if (left < right) {
            now[left] = '6';
            now[right] = '9';
            dfs(left+1, right-1, now, low, high, res);
            swap(now[left], now[right]);
            dfs(left+1, right-1, now, low, high, res);
        }
    }
};